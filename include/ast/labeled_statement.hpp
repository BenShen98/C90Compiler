#ifndef ast_labeled_statement
#define ast_labeled_statement

#include "_left_list.hpp"
/*
labeled_statement
0	: IDENTIFIER ':' statement
1	| CASE constant_expression ':' statement
2	| DEFAULT ':' statement
	;
 */

class labeled_statement: public ast_abs{

    int type;
    astPtr exp=0;
    astPtr st;

public:
    labeled_statement(int t, astPtr s): type(t), st(s){}
    labeled_statement(astPtr e, astPtr s): type(1), exp(e), st(s) {}

    ~labeled_statement() override{
        delete exp;
        delete st;
    }

    void py(std::string& dst) const override{
        notImplemented();
    }

    void mp() const override{
        notImplemented();

    }

};

#endif
