#ifndef direct_abstract_declarator
#define direct_abstract_declarator

#include "_ast_abs.hpp"
#include <string>
/*
direct_abstract_declarator
X	: '(' abstract_declarator ')'
//	| '[' ']'
2   | '[' constant_expression ']'
//	| direct_abstract_declarator '[' ']'
3  	| direct_abstract_declarator '[' constant_expression ']'
//	| '(' ')'
//	| '(' parameter_type_list ')'
//	| direct_abstract_declarator '(' ')'
//	| direct_abstract_declarator '(' parameter_type_list ')'
//	;
 */



class direct_abstract_declarator: public ast_abs{
    int type;
    astPtr direct=0;
    astPtr conExp;


public:
    direct_abstract_declarator(int t, astPtr p):type(t),direct(p){}
    direct_abstract_declarator(int t, astPtr p, astPtr c):type(t),direct(p),conExp(c){}



    ~postfix_expression() override{
        delete direct;
        delete conExp;
    }


    void mp(Result& result) const override{

        Result r;
        conExp->mp(r);

        if(direct!=NULL){
            direct->mp(result);
        }

        result.addr.push_back(r.num);

    }

};



#endif
