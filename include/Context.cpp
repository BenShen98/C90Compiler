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

/*
 * return true when function not found
 */
bool Context::getFunc(std::string name, Functions::const_iterator& func) {
    func=functions.find(name);
    if(func==functions.end()){
        return true;
    }
    return false;
}