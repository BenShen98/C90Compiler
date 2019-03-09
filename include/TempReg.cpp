//
// Created by ben on 2019/3/2.
//

#include "TempReg.hpp"
#include <iostream>
#include <bitset>

/*
 * This function will
 * 1. return first empty register
 * 2. if not empty register, spill register with lowest id to stack
 */
//int TempReg::getFreeReg() {
//    int min_id=-1;
//    for(int i=0;i<TREG_SIZE;++i){
//        if(tReg[i].id<0){
//            //the tReg[i] is empty
//            return i;
//        }
//    }
//
//    //no free reg
//    return -1;
//}

int TempReg::findReg(int id) {
    for(int i=0;i<TREG_SIZE;++i){
        if(tReg[i].id==id){
            return i;
        }
    }

    //reg not found
    return -1;
}

std::string TempReg::regName(int regIdx) {
    if(regIdx<TREG_SIZE){
        return "$t" + std::to_string(regIdx);
    } else{
        throw std::runtime_error("only support 8 temp reg");
    }
}

//return true if was found and freed, return false if no such id in reg
bool TempReg::freeRegById(int id) {
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

void TempReg::debugReg() {
    std::cerr<<"\n# TReg dump\n#\tregName,\tStackID,\ttype(MSB -- LSB)\n";
    for(unsigned i=0;i<TREG_SIZE;++i){
        std::cerr<<"#\t"<< regName(i) <<",\t\t"<< tReg[i].id <<",\t\t"<< std::bitset<32>(tReg[i].type) <<",\n";
    }
    std::cerr<<"\n";

}

int TempReg::setReg(int regId, int id, int type) {
    if(tReg[regId].id<0){
        tReg[regId].id=id;
        tReg[regId].type=type;
        return regId;
    } else{
        throw std::runtime_error("TReg "+regName(regId)+"already in use by "+ std::to_string(tReg[regId].id)+"\n");
    }
}

bool TempReg::isRegTaken(int regId) {
    return (tReg[regId].id<0);
}
