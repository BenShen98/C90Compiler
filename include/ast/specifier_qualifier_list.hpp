#ifndef specifier_qualifier_list_hpp
#define specifier_qualifier_list_hpp

#include "_right_list.hpp"

/*
specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;
	;
 */

class specifier_qualifier_list: public right_list{

public:
    specifier_qualifier_list(astPtr e, astPtr l)
        :right_list(e,l){}

    specifier_qualifier_list(astPtr e)
        :right_list(e){}


};

#endif
