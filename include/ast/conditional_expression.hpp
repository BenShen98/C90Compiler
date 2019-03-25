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

    void mp(Result& para) const override{
        if (is_true==NULL){
        //logical_or_expression
            exp->mp(para);
        }else{
        //logical_or_expression '?' expression ':' conditional_expression
            para.id=mips.reserveId(4,TYPE_SIGNED_INT,"cond temp");
            para.freeable= true;

            Result expResult;
            exp->mp(expResult);

            std::string elsestart=mips.mkLabel("elseStart");
            std::string elseend=mips.mkLabel("elseEnd");

            //if
            mips.bZero(false, expResult.id, elsestart); //skip s1 when false

            //s1
            Result r1;
            is_true->mp(r1);//get id & freeable
            mips.assignment(para.id,r1.id,ASSIGN,r1.freeable);
            mips.branch(elseend);

            //s2
            Result r2;
            mips.insertLabel(elsestart);
            is_false->mp(r2);
            mips.assignment(para.id,r2.id,ASSIGN,r2.freeable);

            //endif
            mips.insertLabel(elseend);

        }
    }

};

#endif
