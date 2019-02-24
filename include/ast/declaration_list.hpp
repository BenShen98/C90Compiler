#ifndef ast_declaration_list
#define ast_declaration_list

#include "_right_list.hpp"

/*
declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;
 */

class declaration_list: public right_list{

public:
    declaration_list(astPtr e, astPtr l)
        :right_list(e,l){}

    declaration_list(astPtr e)
        :right_list(e){}

};

#endif
