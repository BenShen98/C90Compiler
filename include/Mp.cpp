//
// Created by ben on 2019/3/6.
//

#include "Mp.hpp"

#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <stdexcept>
#include <regex>
#include <fstream>



extern std::ofstream ffout;

/*
 * constructor & destructor for frame, clear register
 */

    void Mp::newFrame(std::string name) {
        /*
         * reset all information except the functions's mapping
         */

        //reset buffer
        stack_size=0;
        buffer.clear();
        postEditPtr.clear();

        //reset temporary reg
        freshCounter=0;
        tGeneralReg = std::vector<Reg>(T_GENERAL_REG_SIZE,{MASK_IS_FREE,0,0});
    //    tFloatReg = std::vector<Reg>(T_FLOAT_REG_SIZE,{MASK_IS_FREE,0,0});

        //reset stack
        top_id=0;
        entries = std::vector<Entry>(1,{0,0,TYPE_SINGED_INT,""});

        //reset function name
        arg_top_id=0;
        funcName=name;
    //    args.clear();
    //    arg_top_id=0;

    }

    /*
     * flush data
     */
    void Mp::endFrame() {

        //calculate zone for `local and temporaries` and `args`
        arg_top_id=16; //assume no arguement
        stack_size = top_id + 4 + arg_top_id; // space for {local},$RA, {opt_place_holder}, {arg_list}

        if(stack_size&0x4){
            stack_size+=4; //make stack frame 8 byte aligned
        }

        //write back dirty register (not needed, for test only)
        writeBackAll();

/*
 * flush buffer
 */
        // frame setup
        ffout<<"addiu $sp, $sp, -"<<stack_size<<'\n'; // allocate stack
        ffout<<"sw $31, "<<arg_top_id<<"($sp)"<<'\n';

        //flush content
        std::regex edit("_-?[0-9]*_");
        std::smatch m;
        int editIdx=0;
        unsigned bufIdx=0;


        //iteration while not reached end of postEditPtr
        for( ; editIdx<postEditPtr.size() && bufIdx<buffer.size();++bufIdx){
            if(postEditPtr[editIdx]==bufIdx){
                //change offset
                std::regex_search(buffer[bufIdx], m, edit);
                ffout<<m.prefix()<<calOffset(m[0])<<m.suffix();

                //increment id
                ++editIdx;
            }else{
                ffout<<buffer[bufIdx];
            }
        }

        //iteration when reached end of postEditPtr
        for( ; bufIdx<buffer.size();++bufIdx){
                ffout<<buffer[bufIdx];
        }


        //frame delete
        ffout<<"lw $31, "<<arg_top_id<<"($sp)"<<'\n';
        ffout<<"addiu $sp, $sp, "<<stack_size<<'\n'; // deallocate stack
        ffout<<"j $31\n";


    }

    void Mp::dump() {

        std::cerr<<"\n#############################\n# Dump for function "<< funcName <<" #\n#############################\n";
        std::cerr<<"# # Entry dump #\n#\t# add_top #,\t# size(byte) #,\t# type(MSB -- LSB) #,\t\t\t# variable name #\n";
        for(std::vector<Entry>::reverse_iterator rit = entries.rbegin();rit!= entries.rend(); ++rit){
            std::cerr<<"#\t"<< rit->top_id <<",\t\t"<< rit->size <<",\t\t"<< std::bitset<32>(rit->type)<< ",\t" <<rit->name <<",\n";
        }
        std::cerr<<"\n# # TGenReg dump #\n#\t# regName #,\t# StackID #,\t# type(MSB -- LSB) #\n";
        for(unsigned i=0;i<T_GENERAL_REG_SIZE;++i){
            std::cerr<<"#\t"<< tGenRegName(i) <<",\t\t"<< tGeneralReg[i].id <<",\t\t"<< std::bitset<32>(tGeneralReg[i].type) <<",\n";
        }
        std::cerr<<"\n";

    }

/*
 * General register
 */
    std::string Mp::tGenRegName(int regIdx) {
        if(regIdx<T_GENERAL_REG_SIZE){
            return "$t" + std::to_string(regIdx);
        } else{
            throw std::runtime_error("only support 8 temp reg");
        }
    }

    bool Mp::discardGenReg(int id) {
        for(int i=0;i<T_GENERAL_REG_SIZE;++i){
            if(tGeneralReg[i].id==id){
                tGeneralReg[i].type = MASK_IS_FREE; //free register without check if need write back
                return true;
            }
        }
        return false;
    }

/*
 * insertion of new variable/arguement
 */

    int Mp::push_back(int size, std::string data, Type type, std::string identifier) {
        //gen id, allocate space on heap
        top_id+=size;
        entries.push_back({size,top_id,type,identifier});

        //init value
        if(type & MASK_IS_FLOAT){
            //type is single/double float
            throw std::runtime_error("single/double float not supported");
        }else{
            //use general register
            int regId=findFreeGenReg();
            tGeneralReg[regId].id=top_id;
            tGeneralReg[regId].type=type|MASK_IS_DIRTY;
            tGeneralReg[regId].freshness=freshCounter;
            freshCounter++;
            _li(tGenRegName(regId), data, "init variable "+identifier);

        }
        return top_id;
    }

/*
 * Buffers for output assembly
 */

std::string Mp::calOffset(const std::string &str) {//not finished
    int pos=atoi(str.substr(1, str.size()-1).c_str());
    return std::to_string(stack_size-pos); // see my (Ben's) drawing

}

/*
 * Arg passing
 */
//void Mp::addArg(int id) {
//    args.push_back({BY_ID,id,""});
//}
//
//void Mp::addArg_cpArray(int id){
//    throw std::runtime_error("not implemented");
//
//    args.push_back({BY_CP_ARRAY,id,""});
//}
//
//void Mp::addArg_Imm(std::string data){
//    throw std::runtime_error("not implemented");
//
//    args.push_back({BY_IMM,0,data});
//}



/*
 * data modification
 */

    void Mp::writeBackAll() {
        //wire back all general register
        for(int i=0; i<T_GENERAL_REG_SIZE; ++i){
            if( tGeneralReg[i].type & MASK_IS_DIRTY ){
                sw_sp(tGenRegName(i),tGeneralReg[i].id,"write back");
            }
        }


        //TODO write back all FP register
    }

    int Mp::getId(std::string identifier, int offset) {
        //find matching name from top of the stack (itr backwards)
        int i =entries.size()-1;

        // whill throw out of rang exception if not found
        while (entries.at(i).name!=identifier){
            --i;
        }

        if(offset!=0){
            if( (entries[i].type & MASK_IS_ARRAY) && (entries[i].size>offset) ){
                //is array
                return entries[i].top_id - offset; //SUB here
            } else{
                // is not array OR index out of range
                throw std::runtime_error(identifier+" is not an array, or index out of range");
            }
        }

        //not array
        return entries[i].top_id;
    }

    EntryPtr Mp::getInfo(int id) const {
        int i=0;

        for( ;id>entries[i].size; ++i){
            id-=entries[i].size;
        }

        return &entries[i];

    }

    int Mp::loadGenReg(int id) {
        int regId=0;

        // check if is already in register
        for (; regId<T_GENERAL_REG_SIZE; ++regId) {
            if (tGeneralReg[regId].id == id) {
                return regId;
            }
        }

        // if not in register, load from stack

        //load context
        EntryPtr entryPtr=getInfo(id);

        //check context
        if( entryPtr->type & MASK_IS_FLOAT ){
            throw std::runtime_error(entryPtr->name+" an single/double float, can not be load to general register");
        }

        // decide which register to use
        regId=findFreeGenReg();

        // set up reg
        tGeneralReg[regId].id=id;
        tGeneralReg[regId].type=entryPtr->type;
        tGeneralReg[regId].freshness=freshCounter;
        freshCounter++;
        lw_sp(tGenRegName(regId), id, "load "+entryPtr->name);
        return regId;

    }

    int Mp::findFreeGenReg() {
        int least_fresh=freshCounter;
        int spill_regId;
        for (int regId=0; regId<T_GENERAL_REG_SIZE; ++regId) {
            if(tGeneralReg[regId].type & MASK_IS_FREE){
                return regId;

            }else if(tGeneralReg[regId].freshness<least_fresh){
                //prepare if need spill
                least_fresh=tGeneralReg[regId].freshness;
                spill_regId=regId;
            }
        }

        //spill reg if is dirty
        if(tGeneralReg[spill_regId].type & MASK_IS_DIRTY){
            // only write back when is dirty
            sw_sp(tGenRegName(spill_regId),tGeneralReg[spill_regId].id, "spill reg");
        }
        return spill_regId;
    }

    std::string Mp::readGenReg(int id) {
        return tGenRegName(loadGenReg(id));
    }

    std::string Mp::writeGenReg(int id) {
        int regId=loadGenReg(id);
        tGeneralReg[regId].type |= MASK_IS_DIRTY;
        return tGenRegName(regId);
    }

    int Mp::sizeOf(Type type) {
        if( type & TYPE_DOUBLE_FLOAT ){
            //only double is 8 byte
            return 8;
        }else{
            //all other is 4 byte wide (ptr, int, float, etc
            return 4;
        }
    }
