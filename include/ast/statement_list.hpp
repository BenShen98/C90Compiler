#ifndef ast_statement_list
#define ast_statement_list

#include "_left_list.hpp"

/*
statement_list
	: statement
	| statement_list statement
	;
 */

class statement_list: public left_list{

public:
    statement_list(astPtr l, astPtr e)
        :left_list(l,e){}

    statement_list(astPtr e)
        :left_list(e){}

};

#endif
