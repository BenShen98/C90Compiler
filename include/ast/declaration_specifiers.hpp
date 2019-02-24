#ifndef ast_declaration_specifiers
#define ast_declaration_specifiers

#include "_left_list.hpp"

/*
declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
X	| type_qualifier
X	| type_qualifier declaration_specifiers
	;
 */

class declaration_specifiers: public left_list{

public:
    declaration_specifiers(astPtr l, astPtr e)
        :left_list(l,e){}

    declaration_specifiers(astPtr e)
        :left_list(e){}

};

#endif
