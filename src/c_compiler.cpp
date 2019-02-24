#include "ast.hpp"

#include <iostream>
#include <string>

//debug dummy
void dd(){
    int x;
}

int  main(int argc, char* argv[]){

    std::cout<<"building tree"<<std::endl;

    const ast_abs * root = parseAST();

    dd();


    std::string pyFile;
    root->py(pyFile);
    std::cout<<pyFile;

    return 0;
}

