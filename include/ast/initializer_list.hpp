#ifndef ast_initializer_list
#define ast_initializer_list

#include "_left_list.hpp"

/*
initializer_list
	: initializer
	| initializer_list ',' initializer
	;
 */

class initializer_list: public left_list{

public:
    initializer_list(astPtr l, astPtr e)
        :left_list(l,e){}

    initializer_list(astPtr e)
        :left_list(e){}

};

#endif
