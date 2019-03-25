#ifndef ast_postfix_expression
#define ast_postfix_expression

#include "_ast_abs.hpp"
#include <string>
/*
postfix_expression
X	: primary_expression
1	| postfix_expression '[' expression ']'
2	| postfix_expression '(' ')'
3	| postfix_expression '(' argument_expression_list ')'
4	| postfix_expression '.' IDENTIFIER
5	| postfix_expression PTR_OP IDENTIFIER
6	| postfix_expression INC_OP
7	| postfix_expression DEC_OP
	;
 */



class postfix_expression: public ast_abs{
    int type;
    astPtr pt;

    // make a union for two type below
    astPtr op=0; //for only case 1,3 optional parameter
    std::string * id; //only for case 4,5


public:
    postfix_expression(int t, astPtr p):type(t),pt(p){} //case 0,2,6,7
    postfix_expression(int t, astPtr p, std::string * i):type(t),pt(p), id(i){} //case 4,5
    postfix_expression(int t, astPtr p, astPtr o):type(t),pt(p), op(o){} //case 1,3


    ~postfix_expression() override{
        delete pt;
        delete op;
        delete id;
    }

    void py(std::string& dst) const override{
        std::string p,o;
        pt->py(p);

        switch (type){
            case 0: //primary_expression
                dst=p;
                break;

            case 2: //postfix_expression '(' ')'
                dst= p + "()";
                break;

            case 3: //postfix_expression '(' argument_expression_list ')'
                op->py(o);
                dst = p + '(' + o + ')';
                break;

            default:
                notImplemented();
                break;

        }

    }

    void mp(Result& result) const override{
        Result postfix;
        switch (type){

            case 2: //postfix_expression '(' ')'
            case 3:
                postfix.type=TYPE_VOID; //set void flag, request str
                pt->mp(postfix);

                mips.callFunc(postfix.str);

                if(type==3)
                    op->mp();

                result.id = mips.commitCall();
                result.freeable= true;

                break;

            case 6: //INC_OP

                pt->mp(postfix);
                result.id=mips.addi(false,postfix.id,"1");//copy of org
                result.freeable= true;

                break;

            case 7: //DEC_OP
                pt->mp(postfix);
                result.id=mips.addi(false,postfix.id,"1"); //copy of org
                result.freeable= true;

                break;


            default:
                notImplemented();
        }
    }

};



#endif
