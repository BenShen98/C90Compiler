#ifndef ast_expression_statement
#define ast_expression_statement

#include "_left_list.hpp"

/*
expression_statement
	: ';'
	| expression ';'
	;
 */

class expression_statement: public ast_abs{
    astPtr exp=0;

public:
    expression_statement() {}

    expression_statement(astPtr e)
        :exp(e){}

    ~expression_statement() override{
        delete exp;
    }

    void py(std::string& dst) const override{
       if(exp!=NULL){
           exp->py(dst);
       }

    }

    void mp() const override{
        notImplemented();
    }

};

#endif
