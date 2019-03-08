//
// Created by ben on 2019/2/20.
//
#include <iostream>
#include <string>
#include <fstream>
#include <bitset>



#include "Mp.hpp"

std::ofstream ffout;



int main(){

    Mp mp;
    ffout.open("MpOut.temp");

    std::cout<<"test type\n";
    Type t1=TYPE_UNSIGNED_INT|MASK_IS_DIRTY;
    Type t2=TYPE_DOUBLE_FLOAT;

    Type t3=t1&t2;//give 01

    std::cout<<"\texpect 0....01, get \t"<<std::bitset<32>(t3)<<'\n';

    t2&=t1;
    std::cout<<"\texpect 1....11, get \t"<<std::bitset<32>(t1)<<'\n';
    std::cout<<"\texpect 0....01, get \t"<<std::bitset<32>(t2)<<'\n';




    ffout.close();


//    Stack stack;
//    stack.debugEntry();
//    stack.debugFrame();


}