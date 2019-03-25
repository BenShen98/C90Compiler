#ifndef ast_constant_expression
#define ast_constant_expression

#include "_ast_abs.hpp"
/*
 *
    constant_expression
	: conditional_expression
	;
 */

class constant_expression: public ast_abs{
    astPtr exp;

public:
    constant_expression(astPtr e):exp(e){}

    ~constant_expression() override{
        delete exp;
    }

    virtual void py(std::string& dst) const override{

        exp->py(dst);

    }


    virtual void mp(Result& result) const override{
        result.type=TYPE_VOID;
        exp->mp(result);

    }

};

#endif