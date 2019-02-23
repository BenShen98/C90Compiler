#ifndef ast_cast_expression
#define ast_cast_expression

#include "_ast_abs.hpp"
#include <iostream>
/*
cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

 */

class cast_expression: public ast_abs{
    astPtr exp;
    astPtr type=0;

public:
    cast_expression(astPtr t, astPtr e):type(t),exp(e){}
    cast_expression(astPtr e):exp(e){}

    ~cast_expression() override{
        delete exp;
        delete type;
    }

    void py(std::string& dst) const override{
        if(type!=0){
            //unary_expression
            exp->py(dst);
        }else{
            //'(' type_name ')' cast_expression
            std::cerr<<"Python does not support type cast\n";
            notImplemented();
        }
    }

    void mp() const override{
        notImplemented();
        if(type!=0){
            //unary_expression


        }else{
            //'(' type_name ')' cast_expression

        }
    }

};

#endif
