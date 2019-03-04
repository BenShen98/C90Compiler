//
// Created by ben on 2019/2/20.
//
#include <iostream>
#include <string>
#include <fstream>


#include "Mp.hpp"

std::ofstream ffout;



int main(){

    Mp mp;
    ffout.open("MpOut.temp");



    mp.debugStack();
    mp.debugTReg();


    ffout.close();


//    Stack stack;
//    stack.debugEntry();
//    stack.debugFrame();


}