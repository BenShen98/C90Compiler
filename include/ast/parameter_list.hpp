#ifndef ast_parameter_list
#define ast_parameter_list

#include "_left_list.hpp"

/*
parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;
 */

class parameter_list: public left_list{

public:
    parameter_list(astPtr l, astPtr e)
        :left_list(l,e){}

    parameter_list(astPtr e)
        :left_list(e){}

};

#endif
