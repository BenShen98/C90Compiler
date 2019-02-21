#ifndef ast_function_definition
#define ast_function_definition

#include "_ast_abs.hpp"

/*
function_definition
0 : declaration_specifiers declarator declaration_list compound_statement     (K&R-style ?)  int foo(a, b) int a; double b; { ... }
1 | declaration_specifiers declarator compound_statement                      int, main(int a, ...), {...}
2 | declarator declaration_list compound_statement                            (K&R-style ?)
3 | declarator compound_statement                                             main(int a, ...), {...}, ASSUME INT https://stackoverflow.com/questions/30542092/function-without-return-type-specified-in-c
;

 simplify logic if dont need KR style
*/



class function_definition: public ast_abs{
    int type;
    astPtr declaration_specifiers;
    astPtr declarator;
//    astPtr declaration_list;
    astPtr compound_statement;


public:
//    function_definition(astPtr a, astPtr b, astPtr c):declaration_specifiers(a),declarator(b), compound_statement(c), type(1){}
    function_definition(astPtr b, astPtr c):declarator(b), compound_statement(c), type(3){}


    ~function_definition() override{
        delete declaration_specifiers;
        delete declarator;
//        delete declaration_list;
        delete compound_statement;
    }

    void py(std::string& dst) const override{
        std::string func,body;
        declarator->py(func);

        compound_statement->py(body);
        indent(body);

        dst = "def " + func + ":\n" + body;

//        switch (type){
//            case 1:
//                dst="def "+
//                break;
//            case 2:
//
//                break;
//            default:
//                notImplemented();
//        }

    }

    void mp() const override{
        switch (type){

            default:
                notImplemented();
        }
    }

};

#endif
