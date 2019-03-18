#ifndef ast_expression
#define ast_expression

#include "_left_list.hpp"

/*
expression
	: assignment_expression
	| expression ',' assignment_expression
	;
 */

class expression: public left_list{

public:
    expression(astPtr l, astPtr e)
        :left_list(l,e){}

    expression(astPtr e)
        :left_list(e){}

    /*
     *  CAN not use default method, because comma operator is sequence point
     */
    virtual void mp(Result& result) const override{
        element->mp(result);
        list->mp(result);
    }

    virtual void mp() const override{
        element->mp();
        list->mp();
    }

};

#endif
