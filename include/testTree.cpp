//
// Created by ben on 2019/2/20.
//
#include <iostream>
#include <string>

#include "ast.hpp"

int main(){
    astPtr  ast=0;
    std::string pythonCode;

    ast=new translation_unit(
            new translation_unit(
                    new te("1"),
                    new te("2")
                    ),
            new te("3")
            );
    ast->py(pythonCode);

    std::cout<<pythonCode<<"\n";
}