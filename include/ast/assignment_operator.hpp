#ifndef ast_assignment_operator
#define ast_assignment_operator

/*
 *
 * assignment_operator were only used by the assignment_expression,
 * in yacc for unary_operator, simply put ($$=EQUAL,$$=MUL_ASSIGN etc)
 *
assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;
 */

enum enum_assignment {ASSIGN, MULA, DIVA, MODA, ADDA, SUBA, LEFTA, RIGHTA, ANDA, XORA, ORA};


#endif