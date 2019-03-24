#ifndef ast_unary_expression
#define ast_unary_expression

#include "_ast_abs.hpp"
#include <string>
/*CHECKED
unary_expression
X	: postfix_expression        { $$=$1;}
1	| INC_OP unary_expression
2	| DEC_OP unary_expression
	| unary_operator cast_expression        SPECIAL CASE unary_operator IS TERMINAL
3	| SIZEOF unary_expression
4	| SIZEOF '(' type_name ')'
    ;

special case for unary_operator:
'&'
'*'
'+'
'-'
'~'
'!'
 */



class unary_expression: public ast_abs{
    int type;
    astPtr pt;

public:
    unary_expression(int t, astPtr p):type(t),pt(p){}


    ~unary_expression() override{
        delete pt;
    }

    void py(std::string& dst) const override{
        std::string p;
        pt->py(p);

        switch (type){

            case '+':
                dst='+' + p;
                break;

            case '-':
                dst='-' + p;
                break;

            case '!':
                dst='!' + p;
                break;

            case '~':
                dst='~' + p;
                break;

            default:
                notImplemented();
                //ignore & * unary_operator
                break;

        }

    }

    void mp(Result& result) const override{


        if(!isVoid(result.type)){

            pt->mp(result);

            switch (type){
                case 1:
                    //per increment, self assign,
                    //only alter value pointed by id, does not change result.id AND result.freeable
                    mips.addi(true, result.id, "1");

                    break;
                case 2:
                    mips.addi(true, result.id, "-1");

                    break;
                case '-':
                    result.id=mips.negation('-',result.id,false);
                    break;

                case '+':
                    break;

                case '~':
                    result.id=mips.negation('~',result.id,false);
                    break;

                case '!':
                    result.id=mips.negation('!',result.id,false);
                    break;

                default:
                    notImplemented();

            }

        }else{

//            0	: postfix_expression
//            1	| INC_OP unary_expression
//            2	| DEC_OP unary_expression
//                          | unary_operator cast_expression        SPECIAL CASE unary_operator IS TERMINAL
//            3	| SIZEOF unary_expression
//            4	| SIZEOF '(' type_name ')'
//                    ;
//
//            special case for unary_operator:
//            '&'
//            '*'
//            '+'
//            '-'
//            '~'
//            '!'
//            */

            pt->mp(result);

            switch (type){

                case '-':
                    result.num = -result.num;
                    break;

                case '~':
                    result.num = ~result.num;
                    break;

                case '!':
                    result.num = !result.num;
                    break;

                default:
                    notImplemented();
                    //ignore & * unary_operator
                    break;

            }

        }

    }

};



#endif
