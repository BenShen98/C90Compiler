#ifndef ast_unary_expression
#define ast_unary_expression

#include "_ast_abs.hpp"
#include <string>
/*CHECKED
unary_expression
0	: postfix_expression
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
            case 0:
                dst=p;
                break;

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
        mp->mp(result);

        switch (type){
            case 0:
                //done
                break;
            case 1:
                //per increment, self assign,
                //only alter value pointed by id, does not change result.id AND result.freeable
                mp.addi(true, result.id, "1", false, "per increment id "+ std::to_string(result.id) );

                break;
            case 2:
                mp.addi(true, result.id, "-1", false, "per decrement id "+ std::to_string(result.id) );
                break;

            default:
                notImplemented();
        }
    }

};



#endif
