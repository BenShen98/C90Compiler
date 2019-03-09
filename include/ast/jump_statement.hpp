#ifndef ast_jump_statement
#define ast_jump_statement

#include "_left_list.hpp"
/*
jump_statement
0	: GOTO IDENTIFIER ';'
1	| CONTINUE ';'
2	| BREAK ';'
3	| RETURN ';'
4	| RETURN expression ';'
	;
 */

class jump_statement: public ast_abs{

    int type;
    astPtr exp=0;

public:
    jump_statement(int t): type(t){}
    jump_statement(int t, astPtr e): type(t), exp(e) {}

    void py(std::string& dst) const override{
        std::string e;
        switch (type){
            case 3: // RETURN ';'
                dst="return";
                break;
            case 4: // RETURN expression ';'
                exp->py(e);
                dst="return " + e;
                break;

            default:
                notImplemented();
        }
    }

    void mp(Result& result) const override{
        notImplemented();

    }

};

#endif
