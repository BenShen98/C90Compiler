#ifndef ast_declaration_list
#define ast_declaration_list

#include "_right_list.hpp"

/*
declaration_list
X 	: declaration ($$=$1 in yacc)
	| declaration_list declaration
	;
 */

class declaration_list: public left_list{

public:
    declaration_list(astPtr l, astPtr e)
        :left_list(l,e){}

    declaration_list(astPtr e)
        :left_list(e){}

    virtual void py(std::string& dst) const override{
        std::string e, l;
        list->py(l);

        element->py(e);
        dst = l + '\n' + e;

    }

    void mp(Result& result) const override{
        list->mp(_dummy_);
        element->mp(_dummy_);
    }
};

#endif
