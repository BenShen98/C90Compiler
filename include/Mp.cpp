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
    tGeneralReg = std::vector<Reg>(T_GENERAL_REG_SIZE,{TYPE_SINGED_INT,-1,0});
//    tFloatReg = std::vector<Reg>(T_FLOAT_REG_SIZE,{0,-1});

    //reset stack
    top_id=0;
    entries = std::vector<Entry>(1,{0,0,TYPE_SINGED_INT,""});

    //reset function name
    funcName=name;
    args.clear();
    arg_top_id=0;

}

/*
 * flush data
 */
void Mp::endFrame() {

    //calculate zone for `local and temporaries` and `args`
    arg_top_id=16; //assume no arguement
    stack_size = 4 + top_id + arg_top_id; // space for {local},$RA, {opt_place_holder}, {arg_list}

    if(stack_size&0x4){
        stack_size+=4; //make stack frame 8 byte aligned
    }


    // frame setup
    ffout<<"addiu $sp, $sp, -"<<(stack_size+4)<<'\n'; // allocate stack
    ffout<<"sw $31, "<<stack_size<<"($sp)"<<'\n';

    //flush content
    std::regex edit("_-?[0-9]*_");
    std::smatch m;
    int editIdx=0;
    for(int bufIdx=0;bufIdx<buffer.size();++bufIdx){
        if(postEditPtr[editIdx]==bufIdx){
            //change offset
            std::regex_search(buffer[bufIdx], m, edit);
            ffout<<m.prefix()<<calOffest(m[0])<<m.suffiex();

            //increment id
            ++editIdx;
        }else{
            ffout<<buffer[bufIdx];
        }
    }

    //write back dirty register

    //arguement

    //frame delete
    ffout<<"lw $31, "<<stack_size<<"($sp)"<<'\n';
    ffout<<"addiu $sp, $sp, "<<(stack_size+4)<<'\n'; // deallocate stack
    ffout<<"j $31\n"


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
            if(tReg[i].id==id){
                tReg[i].id=-1; //free register without check if need write back
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
            tGeneralReg[regId].id=id;
            tGeneralReg[regId].type=entryPtr->type;
            tGeneralReg[regId].freshness=freshCounter;
            freshCounter++;
            li(tGenRegName(regId), data, "init variable "+identifier);

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

    int Mp::getId(std::string identifier, int offset) {
        //find matching name from top of the stack (itr backwards)
        int i =entries.size()-1;

        // whill throw out of rang exception if not found
        while (entries.at(i).name!=name){
            --i;
        }

        if(offsetByte!=0){
            if( (entries[i].type & MASK_IS_ARRAY) && (entries[i].size>offsetByte) ){
                //is array
                return entries[i].top_id - offsetByte; //SUB here
            } else{
                // is not array OR index out of range
                throw std::runtime_error(name+"is not an array, or index out of range");
            }
        }

        //not array
        return entries[i].top_id;
    }

    EntryPtr Mp::getInfo(id) {

        for(int i=0; id>entries[i].size; ++i){
            id=entries[i].size;
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
        EntryPtr entryPtr;
        entryPtr=getInfo(id);

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
        lw_sp(tGenRegName(regId), id, "load "+entryPtr->name)
        return regId;

    }

    int Mp::findFreeGenReg() {
        int least_fresh=freshCounter;
        int spill_regId;
        for (int regId=0; regId<T_GENERAL_REG_SIZE; ++regId) {
            if(tGeneralReg[regId].id<0){
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
        return loadGenReg(id);
    }

    std::string Mp::writeGenReg(int id) {
        int regId=loadGenReg(id);
        tGeneralReg[regId].type =| MASK_IS_DIRTY;
        return regId;
    }

