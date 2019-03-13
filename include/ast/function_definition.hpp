#ifndef ast_function_definition
#define ast_function_definition

#include "_ast_abs.hpp"
/*
function_definition
 : ~~declaration_specifiers declarator declaration_list compound_statement~~     REMOVED (K&R-style)  int foo(a, b) int a; double b; { ... }
 | declaration_specifiers declarator compound_statement                      int, main(int a, ...), {...}
 | ~~declarator declaration_list compound_statement~~                            REMOVED (K&R-style)
 | declarator compound_statement                                             main(int a, ...), {...}, ASSUME INT https://stackoverflow.com/questions/30542092/function-without-return-type-specified-in-c
;
*/



class function_definition: public ast_abs{
    astPtr declaration_specifiers;
    astPtr declarator;
    astPtr compound_statement;


public:
    function_definition(astPtr a, astPtr b, astPtr c):declaration_specifiers(a),declarator(b), compound_statement(c){}
    function_definition(astPtr b, astPtr c):declarator(b), compound_statement(c){}


    ~function_definition() override{
        delete declaration_specifiers;
        delete declarator;
//        delete declaration_list;
        delete compound_statement;
    }

    void py(std::string& dst) const override{
        std::string func,body,global;
        declarator->py(func);

        compound_statement->py(body);
        for(int i = 0; i<globalvar.size();i++){
          global += "global " + globalvar[i] + '\n';
          //std::cerr<<globalvar[i]<<std::endl;
        }
        body=global+body;
        indent(body);

        dst = "def " + func + ":\n" + body + "\n\n";
        //std::cerr<<"WARNING THIS IS PRINTING"<<dst<<std::endl;

    }

    void mp() const override{

        //todo: log this's return type function
//        if (declaration_specifiers==NULL){
//            //declarator compound_statement  , default int as return type
//
//        }else{
//            //itr declaration_specifiers to get type
//
//        }

        //todo: log function name,  parameter type
//        declarator->mp(_dummy_);

        // compile function
        compound_statement->mp();


    }

};

#endif
