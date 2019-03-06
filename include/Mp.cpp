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

std::string Mp::calOffset(const std::string &str) {
    int pos=atoi(str.substr(1, str.size()-1).c_str());

}

void Mp::flush() {//not finished
    std::regex edit("_[0-9]*_");
    std::smatch m;

    //TODO 8 byte alignment not considered, ADD LR

    // frame setup
    ffout<<"addi $sp, $sp, -"<<(top_id+4); // allocate stack

    //flush content
    int editIdx=0;
    for(int bufIdx=0;bufIdx<buffer.size();++bufIdx){
        if(postEditPtr[editIdx]==bufIdx){
            //change offset
            std::regex_search(buffer[bufIdx], m, edit);
            ffout<<m.prefix()<<calOffest(m[0])<<m.suffiex();


        }else{
            ffout<<buffer[bufIdx];
        }
    }

    //frame delete
    ffout<<"addi $sp, $sp, "<<(top_id+4); // deallocate stack

}



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

    const Mp::Entry * const Mp::getInfo(id) {

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
        const Mp::Entry * const entryPtr;
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

        //spill reg
        std::string regName=tGenRegName(spill_regId);
        sw_sp(regName,tGeneralReg[spill_regId].id, "spill reg");
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

