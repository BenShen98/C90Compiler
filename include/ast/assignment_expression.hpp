#ifndef ast_assignment_expression
#define ast_assignment_expression

#include "_ast_abs.hpp"
/*
assignment_expression
0	: conditional_expression
1	| unary_expression assignment_operator assignment_expression
	;

 */

class assignment_expression: public ast_abs{
    astPtr expression;
    astPtr assignment_operator=0;
    astPtr assignment_exp=0;

public:
    assignment_expression(astPtr conditional_expression):expression(conditional_expression){}
    assignment_expression(astPtr a, astPtr b, astPtr c):expression(a),assignment_operator(b),assignment_exp(c){}


    ~assignment_expression() override{
        delete expression;
        delete assignment_exp;
        delete assignment_operator;
    }

    void py(std::string& dst) const override{
        if(assignment_exp==NULL){
            //conditional_expression
            notImplemented();
        } else{
            //unary_expression assignment_operator assignment_expression;
            notImplemented();
        }
    }

    void mp() const override{
        notImplemented();

    }

};

#endif
