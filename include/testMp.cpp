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

    mp.newFrame("test");
    mp.push_back(4,"123456",TYPE_SINGED_INT,"int");
    mp.push_back(8,"5.3",TYPE_UNSIGNED_INT,"a double pretend as unsigned");
    mp.endFrame();
    mp.dump();



    ffout.close();


//    Stack stack;
//    stack.debugEntry();
//    stack.debugFrame();


}