//
// Created by ben on 2019/2/20.
//
#include <iostream>
#include <string>

#include "ast.hpp"

/*
 * Tree for C code below (default int)
 *
 * main(){
 *      int x=1;
 *      return x;
 * }
 */



int main(){
    astPtr  ast=0;
    std::string pythonCode;


//    ast= new te("statements etc");

    ast=new translation_unit(
                new external_declaration(
                        0,
                        new function_definition(
                                new declarator(
                                        new direct_declarator(
                                                3,
                                                new direct_declarator("main"),
                                                NULL
                                                )
                                        ),
                                        new compound_statement(
                                                new declaration_list(
                                                        new declaration(
                                                                new te("declaration_specifiers"),
                                                                new init_declarator_list(
                                                                        new init_declarator(
                                                                                new direct_declarator(
                                                                                        "x"
                                                                                        )
                                                                                )
                                                                        )
                                                                )
                                                        ),
                                                new statement_list(
                                                        new jump_statement(RETURN)
                                                        )
                                                )
                                )
                        )
            );

    ast->py(pythonCode);

    std::cout<<pythonCode<<"\n";
}