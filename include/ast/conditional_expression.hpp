#ifndef ast_conditional_expression
#define ast_conditional_expression

#include "_ast_abs.hpp"

/*CHECKED
conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;
*/



class conditional_expression: public ast_abs{
    astPtr exp;
    astPtr is_true=0;
    astPtr is_false=0;


public:
    conditional_expression(astPtr e, astPtr t, astPtr f):exp(e),is_true(t), is_false(f){}
    conditional_expression(astPtr e):exp(e){}


    ~conditional_expression() override{
        delete exp;
        delete is_true;
        delete is_false;
    }

    void py(std::string& dst) const override{
        if (is_true==NULL){
            //logical_or_expression
            exp->py(dst);

        }else{
            //logical_or_expression '?' expression ':' conditional_expression
            notImplemented();
        }

    }

    void mp(Result& result) const override{
        notImplemented();
        if (is_true==NULL){
        //logical_or_expression

        }else{
        //logical_or_expression '?' expression ':' conditional_expression

        }
    }

};

#endif
