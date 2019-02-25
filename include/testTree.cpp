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

    std::string * m = new std::string("main");

    std::string * x = new std::string("x");


//    ast=new translation_unit(
//            new external_declaration(
//                    0,
//                    new function_definition(
//                            new declarator(
//                                    new direct_declarator(
//                                            5,
//                                            new direct_declarator(m),
//                                            NULL
//                                    )
//                            ),
//                            new compound_statement(
//                                    new te("declaration_specifiers"),
//                                    NULL
//
//                            )
//                    )
//            )
//    );
//
//    ast->py(pythonCode);
//    std::cout<<pythonCode<<"\n";


    ast=new translation_unit(
                new external_declaration(
                        0,
                        new function_definition(
                                new declarator(
                                        new direct_declarator(
                                                5,
                                                new direct_declarator(m),
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
                                                                                        x
                                                                                        )
                                                                                )
                                                                        )
                                                                )
                                                        ),
                                                new statement_list(
                                                        new jump_statement(3)
                                                        )
                                                )
                                )
                        )
            );

    std::cout<<"to py"<<"\n";


    ast->py(pythonCode);
    std::cout<<pythonCode<<"\n";


    // ((1<<2)and(a*(xx+yy)))
    ast=new algebra(AND_,
            new algebra(
                    LEFT_,
                    new te("1"),
                    new te("2")
                    ),
            new algebra(
                    MUL,
                    new te("a"),
                    new algebra(
                            ADD,
                            new te("xx"),
                            new te("yy")
                            )
                    )
            );

    ast->py(pythonCode);
    std::cout<<pythonCode<<"\n";

    delete ast;
}