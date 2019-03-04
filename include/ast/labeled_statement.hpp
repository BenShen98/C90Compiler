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

    std::string * str;

public:
    labeled_statement(astPtr s): type(2), st(s){}
    labeled_statement(astPtr e, astPtr s): type(1), exp(e), st(s) {}
    labeled_statement(std::string * s, astPtr sta): type(0), str(s), st(sta) {}

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
    std::string c()const override{
      switch(type){
        case 0:
          return *str + ':' + st->c();
        case 1:
          return "case " + exp->c() + ':' + st->c();
        case 2:
          return "default:" + st->c();
      }
    }

};

#endif
