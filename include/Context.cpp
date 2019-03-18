//
// Created by Ben Shen on 2019-03-15.
//

#include "Context.hpp"
#include <iostream>


void Context::addFunc(std::string name, Type returnType){
    _funcName=name;
    _funcParas = Paras (1, {returnType, "returnVal"});
}

//void Context::addFuncPara(Type paraType, std::string paraName){
//    _funcParas.push_back({paraType, paraName});
//}

void Context::commitFunc(){
    functions[_funcName] = _funcParas;
}

Functions::const_iterator Context::getFunc(std::string name) {
    Functions::const_iterator func=functions.find(name);
    if(func==functions.end()){
        throw std::runtime_error("function "+name+" is not defined");
    }
    return func;
}