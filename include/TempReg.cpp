//
// Created by ben on 2019/3/2.
//

#include "TempReg.hpp"



int TempReg::findFreeReg() {
    for(int i=0;i<TREG_SIZE;++i){
        if(tReg[i].id<0){
            return i;
        }
    }

    //no free reg
    return -1;
}

int TempReg::find(int id) {
    for(int i=0;i<TREG_SIZE;++i){
        if(tReg[i].id==id){
            return i;
        }
    }

    //reg not found
    return -1;
}

std::string TempReg::MPname(int regIdx) {
    if(regIdx<7){
        return "$t" + regIdx;
    } else{
        throw std::runtime_error("only support 8 temp reg");
    }
}

bool TempReg::freeReg(int id) {
    for(int i=0;i<TREG_SIZE;++i){
        if(tReg[i].id==id){
            tReg[i].id=-1; //free register without check if need write back
            return true;
        }
    }
    return false;
}

void TempReg::freeRegHigherThan(int id) {
    for(int i=0;i<TREG_SIZE;++i){
        if(tReg[i].id>id){
            tReg[i].id=-1; //free register without check if need write back
        }
    }
}
