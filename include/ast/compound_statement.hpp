#ifndef ast_compound_statement
#define ast_compound_statement

#include "_expression.hpp"
#include <string>
/*
compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;
 */

class compound_statement: public expression{
    astPtr declaration_list=0;
    astPtr statement_list=0;

public:
    compound_statement(astPtr de, astPtr sta):declaration_list(de),statement_list (sta){}

    ~compound_statement() override{
        delete declaration_list;
        delete statement_list;
    }

    void py(std::string& dst) const override{
        std::string d,s;
       if(declaration_list!=NULL){
           declaration_list->py(d);
       }

       if(statement_list!=NULL){
           statement_list->py(s);
       }

       dst = d + '\n' + s;
    }

    void mp() const override{
        notImplemented();
    }

};

#endif
