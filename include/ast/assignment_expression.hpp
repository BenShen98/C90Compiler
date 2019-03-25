#ifndef ast_assignment_expression
#define ast_assignment_expression

#include "_ast_abs.hpp"
#include "assignment_operator.hpp"
/*CHECKED
assignment_expression
0	: conditional_expression
1	| unary_expression assignment_operator assignment_expression
	;

 */

class assignment_expression: public ast_abs{
    astPtr unary_expression=0;
    enum_assignment assignment_operator=ASSIGN;
    astPtr expression; // this will be the conditional_expression in case 0, and assignment_expression in case 1

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

  virtual std::string c() const override{
        if(unary_expression==NULL){
            //conditional_expression
            return expression->c();
        } else{
            //unary_expression assignment_operator assignment_expression;
            switch (assignment_operator){
                case ASSIGN:
                    return unary_expression->c() + '=' + expression->c() ;
                    break;

                case MULA:
                    return unary_expression->c() + "*=" + expression->c() ;
                    break;

                case DIVA:
                    return unary_expression->c() + "/=" + expression->c() ;
                    break;

                case MODA:
                    return unary_expression->c() + "%=" + expression->c() ;
                    break;

                case ADDA:
                    return unary_expression->c() + "+=" + expression->c() ;
                    break;

                case SUBA:
                    return unary_expression->c() + "-=" + expression->c() ;
                    break;

                case LEFTA:
                    return unary_expression->c() + "<<=" + expression->c() ;
                    break;

                case RIGHTA:
                    return unary_expression->c() + ">>=" + expression->c() ;
                    break;

                case ANDA:
                    return unary_expression->c() + "&=" + expression->c() ;
                    break;

                case XORA:
                    return unary_expression->c() + "^=" + expression->c() ;
                    break;

                case ORA:
                    return unary_expression->c() + "|=" + expression->c();
                    break;

            }

        }
    }

    //used ONLY by assignment_expression
    void mp() const override{
        //parent node are expression
        Result result;
        mp(result);

        mips.addArg(result.id);

    }

    void mp(Result& result) const override{
        //parent node are assignment_expression
        if(unary_expression==NULL){
            //base case
            expression->mp(result);
        } else{
            //get lvalue
            unary_expression->mp(result);

            //eval expression
            Result exp;
            expression->mp(exp);

            //perform assignment
            mips.assignment(result.id,exp.id,assignment_operator,exp.freeable);
        }

    }

};

#endif
