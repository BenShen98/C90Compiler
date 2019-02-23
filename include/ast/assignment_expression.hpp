#ifndef ast_assignment_expression
#define ast_assignment_expression

#include "_ast_abs.hpp"
#include "assignment_operator.hpp"
/*
assignment_expression
0	: conditional_expression
1	| unary_expression assignment_operator assignment_expression
	;

 */

class assignment_expression: public ast_abs{
    astPtr unary_expression;
    enum_assignment assignment_operator;
    astPtr expression=0; // this will be the conditional_expression in case 0, and assignment_expression in case 1

public:
    assignment_expression(astPtr conditional_expression):expression(conditional_expression){}
    assignment_expression(astPtr a, enum_assignment b, astPtr c):unary_expression(a),assignment_operator(b),expression(c){}


    ~assignment_expression() override{
        delete expression;
        delete unary_expression;
    }

    void py(std::string& dst) const override{
        std::string e;
        expression->py(e);

        if(unary_expression==NULL){
            //conditional_expression
            dst=e;
        } else{
            //unary_expression assignment_operator assignment_expression;
            std::string u;
            unary_expression->py(u);
            switch (assignment_operator){
                case ASSIGN:
                    dst = u + '=' + e;
                    break;

                case MULA:
                    dst = u + "*=" + e;
                    break;

                case DIVA:
                    dst = u + "/=" + e;
                    break;

                case MODA:
                    dst = u + "%=" + e;
                    break;

                case ADDA:
                    dst = u + "+=" + e;
                    break;

                case SUBA:
                    dst = u + "-=" + e;
                    break;

                case LEFTA:
                    dst = u + "<<=" + e;
                    break;

                case RIGHTA:
                    dst = u + ">>=" + e;
                    break;

                case ANDA:
                    dst = u + "&=" + e;
                    break;

                case XORA:
                    dst = u + "^=" + e;
                    break;

                case ORA:
                    dst = u + "|=" + e;
                    break;

            }

        }
    }

    void mp() const override{
        notImplemented();

    }

};

#endif
