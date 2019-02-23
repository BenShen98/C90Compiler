#ifndef ast_unary_operator
#define ast_unary_operator

/*
 *
 * unary_operator were only used by the unary_expression,
 * in yacc for unary_operator, simply put ($$=$1)
 *
unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;
 */


#endif