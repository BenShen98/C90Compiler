#ifndef ast_declaration
#define ast_declaration

#include "_expression.hpp"

/*
declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;
 */

class declaration: public expression{
    astPtr declaration_specifiers;
    astPtr init_declarator_list=0;

public:
    declaration(astPtr d, astPtr i):declaration_specifiers(d),init_declarator_list(i){}
    declaration(astPtr d):declaration_specifiers(d){}


    ~declaration() override{
        delete declaration_specifiers;
        delete init_declarator_list;
    }

    void py(std::string& dst) const override{
        //ignore type check, by spec only requires int variable
        init_declarator_list->py(dst);
    }

    void mp() const override{
        notImplemented();
    }

};

#endif
