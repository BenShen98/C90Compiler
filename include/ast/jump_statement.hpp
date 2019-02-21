#ifndef ast_jump_statement
#define ast_jump_statement

#include "_left_list.hpp"
/*
jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;
 */

enum jump_type = {GOTO, CONTINUE,BREAK,RETURN };

class jump_statement: public expression{
    jump_type type;
    astPtr exp=0;

public:
    jump_statement(jump_type t): type(t){}
    jump_statement(jump_type t, astPtr e): type(t), exp(e) {}

    void py(std::string& dst) const override{
        switch (type){
            case RETURN:
                if(exp!=NULL){
                    std::string e;
                    exp->py(e);
                    dst="return " + e;
                }else{
                    dst="return"
                }
                break;

            default:
                notImplemented();
        }
    }

    void mp() const override{
        notImplemented();

    }

};

#endif
