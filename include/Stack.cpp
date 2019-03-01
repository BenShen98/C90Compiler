//
// Created by ben on 2019/3/1.
//

#include "Stack.hpp"
#include <iostream>
#include <string>

#include <bitset>


Stack::Stack() {
    entries.reserve(STACK_INIT_SIZE);
}

void Stack::insertFrame(){
    ...
    need_flush=true;
}

void Stack::deleteFrame() {
    ...
    need_flush=true;
}

int Stack::push_back(int size, int type, std::string name){

    //check error before push back
    if( !( type & STACK_TYPE_MASK) ){
        throw std::runtime_error( "Push back to stack, " + std::bitset<32>(type).to_string() + " is not a valid type from variable "+ name +'\n');
    }
    if( size<0 ){
        throw std::runtime_error( "Push back to stack, " + std::to_string(size) + " is not positive from variable "+ name +'\n');
    }

    checkSafeEntryInsert(type);

    entries.push_back({size, type, name});
    need_flush=true;

    return entries.size()-1;
}


std::string Stack::find(int id){
    if(need_flush){
        flush();
    }
    ...
}

std::string Stack::find(std::string n){

    //find matching name from top of the stack (itr backwards)
    int i =entries.size()-1;

    while (entries[i].name!=n){
        --i;
    }

    return find(i);

}


void Stack::flush() {

    need_flush= false;
}

bool Stack::checkSafeEntryInsert(int newEntryType) const {
    std::cerr<<"Warning: stack insertion safe check not run\n";
//        //check if the insert of current entry break the call conversion
//        int previousEntryType=entries.back().type;
//        if( previousEntryType & STACK_EMPTY_MASK ){
//            //caculate if this null is necessary & check the
//        }
//
//
//        // previousEntryType is not EMPTY
//        if( newEntryType & STACK_ARG_MASK ){
//            // the new entry is arg
//
//        }else if( newEntryType & STACK_REG_MASK ){
//            // the new entry is saved reg
//
//        }else{
//            // the new entry is not arg nor reg => is local data(variable)
//
//        }
}

void  Stack::debugFrame(){
//        std::cerr<<"relative address"
}