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
                break;

        }

    }

    void mp() const override{
        switch (type){

            default:
                notImplemented();
        }
    }

};



#endif
