//
// Created by ben on 2019/3/2.
//

#include "Mp.hpp"

#include <climits>

void Mp::debugStack() {
    stack.debugFrame();
    stack.debugEntry();
}

int Mp::findFreeReg() {
    int min_stackid=INT_MAX;
    int reg_id;

    for (unsigned i=0; i<reg.tReg.size(); ++i){

        // if find empty register, return straight away
        if(reg.tReg[i].id<0){
            return i;
        }

        // if not, check if its stackid is lower than min_stackid
        if(reg.tReg[i].id<min_stackid){
            min_stackid=reg.tReg[i].id;
            reg_id=i;
        }
    }

    // there are no empty register
    // spill reg with lowest stackid
    writeBack(reg_id);

    return reg_id;
}

void Mp::insertFrame() {
    stack.insertFrame();
}

void Mp::deleteFrame() {
    int new_maxid;
    new_maxid = stack.deleteFrame();

    //also remove popped stack data from register
    reg.freeRegHigherThan(new_maxid);
}

void Mp::writeBack(int regIdx) {
    int stackid=reg.tReg[regIdx].id;

    if(stackid>0 && stackid<stack.stackSize()) {
        sw_sp(reg.regName(regIdx), stack.getById(stackid), "spill " + stack.entries[stackid].name); //spill
        reg.tReg[regIdx].id = -1; // mark reg as free
    } else{
        throw std::runtime_error("TReg "+reg.regName(regIdx)+"does not contain valid stack id "+std::to_string(stackid)+"\n");
    }
}

void Mp::writeBackAll() {
    for(int i=0; i<TREG_SIZE;++i){
        if(reg.isRegTaken(i)){
            writeBack(i);
        }
    }
}

void Mp::debugTReg() {
    reg.debugReg();
}