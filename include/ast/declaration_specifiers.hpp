#ifndef ast_declaration_specifiers
#define ast_declaration_specifiers

#include "_right_list.hpp"

/*
declaration_specifiers
X	: storage_class_specifier
	| storage_class_specifier declaration_specifiers { $$ = $1; }
X	| type_specifier
	| type_specifier declaration_specifiers { $$ = $1; }
X	| type_qualifier
X	| type_qualifier declaration_specifiers
	;
 */

class declaration_specifiers: public right_list{

public:
    declaration_specifiers(astPtr e, astPtr l)
        :right_list(e,l){}

    declaration_specifiers(astPtr e)
        :right_list(e){}

    // py does not use this node



};

#endif
