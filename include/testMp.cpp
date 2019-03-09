//
// Created by ben on 2019/2/20.
//
#include <iostream>
#include <string>
#include <fstream>
#include <bitset>



#include "Mp.hpp"

std::ofstream ffout;

Mp mp;

void dump(){
    mp.dump();
}

int main(){

    Type a=TYPE_SIGNED_INT;
    Type b=TYPE_UNSIGNED_INT;
    Type c=TYPE_DOUBLE_FLOAT;
    Type d=TYPE_SINGLE_FLOAT;

    setRegDirty(a);
    setRegUnkown(b);
    setRegSync(c);
    setRegEmpty(d);

    std::cout<<std::bitset<32>(a)<<std::endl;
    std::cout<<isRegDirty(a)<<std::endl;
    std::cout<<isRegUnkown(a)<<std::endl;
    std::cout<<isRegSync(a)<<std::endl;
    std::cout<<isRegEmpty(a)<<std::endl<<std::endl;

    std::cout<<std::bitset<32>(b)<<std::endl;
    std::cout<<isRegDirty(b)<<std::endl;
    std::cout<<isRegUnkown(b)<<std::endl;
    std::cout<<isRegSync(b)<<std::endl;
    std::cout<<isRegEmpty(b)<<std::endl<<std::endl;

    std::cout<<std::bitset<32>(c)<<std::endl;
    std::cout<<isRegDirty(c)<<std::endl;
    std::cout<<isRegUnkown(c)<<std::endl;
    std::cout<<isRegSync(c)<<std::endl;
    std::cout<<isRegEmpty(c)<<std::endl<<std::endl;

    std::cout<<std::bitset<32>(d)<<std::endl;
    std::cout<<isRegDirty(d)<<std::endl;
    std::cout<<isRegUnkown(d)<<std::endl;
    std::cout<<isRegSync(d)<<std::endl;
    std::cout<<isRegEmpty(d)<<std::endl;





    ffout.open("MpOut.temp");

    mp.newFrame("test");
    mp.push_back(4,"123456",TYPE_SIGNED_INT,"int");
    mp.push_back(8,"5.3",TYPE_UNSIGNED_INT,"a double pretend as unsigned");
    mp.endFrame();
    mp.dump();



    ffout.close();


//    Stack stack;
//    stack.debugEntry();
//    stack.debugFrame();


}