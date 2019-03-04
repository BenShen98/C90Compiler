//
// Created by ben on 2019/3/1.
//

#include "Stack.hpp"
#include "Mp.hpp"
#include <iostream>
#include <string>

#include <bitset>

Stack::Stack() {
    entries.reserve(STACK_INIT_SIZE);
}

void Stack::insertFrame(){
    //use previous frame as reference point
    int current_top_id = frames.back().top_id;
    frames.push_back({current_top_id, 0});

    //no need to set need_flash flag
    // as does not actually move sp ptr
}

int Stack::deleteFrame() {
    int delete_size=frames.back().size;
    frames.pop_back();

    // delete element in entries
    while (delete_size>0){
        delete_size -= entries.back().size;
        entries.pop_back();
    }

    // check if memory is still aligned
    if(delete_size!=0){
        throw std::runtime_error("unaligned stack when pop frame");
    }

    need_flush=true;

    return frames.back().top_id;
}

int Stack::push_back(int size, int type, std::string name){

    //check error before push back
    if( !( type & STACK_TYPE_MASK) ){
        throw std::runtime_error( "Push back to stack, " + std::bitset<32>(type).to_string() + " is not a valid type, from variable "+ name +'\n');
    }
    if( size<0 || size&0x3 ){
        throw std::runtime_error( "Push back to stack, " + std::to_string(size) + " is not positive or not in BYTE, from variable "+ name +'\n');
    }

    checkSafeEntryInsert(type);

    //update frame info
    frames.back().size += size;
    frames.back().top_id += size;

    //push data to stack
    entries.push_back({size,
                       frames.back().top_id,
                       type,
                       name});


    need_flush=true;

    //return stack id of current element
    return entries.back().top_id;
}


std::string Stack::getById(int id){
    flush();

    int diff = sp - id;

    if(diff<0){
        throw std::runtime_error("item trying to access is above stack");
    }

    //TODO: handel

    return std::to_string(diff) + "($sp)";
}

int Stack::findId(std::string name, int offsetByte) {
    //find matching name from top of the stack (itr backwards)
    int i =entries.size()-1;

    // whill throw out of rang exception if not found
    while (entries.at(i).name!=name){
        --i;
    }

    if(offsetByte!=0){
        if( (entries[i].type & STACK_ARRAY_MASK) && (entries[i].size>offsetByte) ){
            //is array
            return entries[i].top_id + offsetByte;
        } else{
            // is not array OR index out of range
            throw std::runtime_error(name+"array index out of range");
        }
    }

    //not array
    return entries[i].top_id;
}

std::string Stack::getByName(std::string n, int offsetByte){

    return getById( findId(n,offsetByte) );

}


inline void Stack::flush() {
    //use frames data as buffer

    if(need_flush){
        int diff = sp - frames.back().top_id;
        Mp::addi("$sp","$sp", std::to_string(diff));
        sp = frames.back().top_id;
    }

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
    return true;
}

void  Stack::debugFrame(){
        std::cerr<<"\n# Frame dump\n#\tadd_top,\tsize(byte),\n";
        for(std::vector<Frame>::reverse_iterator rit = frames.rbegin();rit!= frames.rend(); ++rit){
            std::cerr<<"#\t"<< rit->top_id <<",\t\t"<< rit->size <<",\n";
        }
        std::cerr<<"\n";
}

void  Stack::debugEntry(){
    std::cerr<<"\n# Entry dump\n#\tadd_top,\tsize(byte),\ttype(MSB -- LSB),\t\t\tvariable name\n";
    for(std::vector<Entry>::reverse_iterator rit = entries.rbegin();rit!= entries.rend(); ++rit){
        std::cerr<<"#\t"<< rit->top_id <<",\t\t"<< rit->size <<",\t\t"<< std::bitset<32>(rit->type)<< ",\t" <<rit->name <<",\n";
    }
    std::cerr<<"\n";

}