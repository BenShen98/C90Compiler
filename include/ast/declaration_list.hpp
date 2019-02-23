#ifndef ast_declaration_list
#define ast_declaration_list

#include "_left_list.hpp"

/*
declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;
 */

class declaration_list: public left_list{

public:
    declaration_list(astPtr l, astPtr e)
        :left_list(l,e){}

    declaration_list(astPtr e)
        :left_list(e){}

};

#endif
