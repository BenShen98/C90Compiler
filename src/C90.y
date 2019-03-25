%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const ast_abs * g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

}

%union{
  const ast_abs * expr;
  std::string *str;
  int i;
  enum_assignment en_ass;
}


%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start top

%type <expr> parameter_declaration primary_expression postfix_expression argument_expression_list unary_expression cast_expression multiplicative_expression additive_expression shift_expression
%type <expr> relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression
%type <expr> parameter_list conditional_expression assignment_expression expression constant_expression declaration declaration_specifiers init_declarator_list init_declarator
%type <expr> parameter_type_list  storage_class_specifier type_specifier  declarator direct_declarator initializer initializer_list labeled_statement compound_statement declaration_list statement_list expression_statement selection_statement iteration_statement jump_statement statement translation_unit external_declaration function_definition
%type <str> IDENTIFIER CONSTANT STRING_LITERAL
%type <i> unary_operator
%type <en_ass> assignment_operator


%%

primary_expression
	: IDENTIFIER		{ $$ = new primary_expression(0, $1); }
	| CONSTANT		{ $$ = new primary_expression(1, $1); }
	| STRING_LITERAL	{ $$ = new primary_expression(2, $1); }
	| '(' expression ')'	{ $$ = new primary_expression(3, $2); }
	;

postfix_expression
	: primary_expression					{ $$ = $1; }
	| postfix_expression '[' expression ']'			{ $$ = new postfix_expression(1, $1, $3); }
	| postfix_expression '(' ')'				{ $$ = new postfix_expression(2, $1); }
	| postfix_expression '(' argument_expression_list ')'	{ $$ = new postfix_expression(3, $1, $3); }
	| postfix_expression '.' IDENTIFIER			{ $$ = new postfix_expression(4, $1, $3); }
	| postfix_expression PTR_OP IDENTIFIER			{ $$ = new postfix_expression(5, $1, $3); }
	| postfix_expression INC_OP				{ $$ = new postfix_expression(6, $1); }
	| postfix_expression DEC_OP				{ $$ = new postfix_expression(7, $1); }
	;

argument_expression_list
	: assignment_expression					{ $$ = $1; }
	| argument_expression_list ',' assignment_expression	{ $$ = new argument_expression_list($1, $3); }
	;

unary_expression
	: postfix_expression			{ $$ = new unary_expression(0, $1); }
	| INC_OP unary_expression		{ $$ = new unary_expression(1, $2); }
	| DEC_OP unary_expression		{ $$ = new unary_expression(2, $2); }
	| unary_operator cast_expression	{ $$ = new unary_expression($1, $2); }
//	| SIZEOF unary_expression		{ $$ = new unary_expression(3, $2); }
//	| SIZEOF '(' type_name ')'		{ $$ = new unary_expression(4, $3); }
	;

unary_operator
	: '&'	{ $$ = '&'; }
	| '*'	{ $$ = '*'; }
	| '+'	{ $$ = '+'; }
	| '-'	{ $$ = '-'; }
	| '~'	{ $$ = '~'; }
	| '!'	{ $$ = '!'; }
	;

cast_expression
	: unary_expression			{ $$ = new cast_expression($1); }
//	| '(' type_name ')' cast_expression	{ $$ = new cast_expression($2,$4); }
	;

multiplicative_expression
	: cast_expression					{ $$ = $1; }
	| multiplicative_expression '*' cast_expression		{ $$ = new algebra(MUL, $1, $3 ); }
	| multiplicative_expression '/' cast_expression		{ $$ = new algebra(DIV, $1, $3 ); }
	| multiplicative_expression '%' cast_expression		{ $$ = new algebra(MOD, $1, $3 ); }
	;

additive_expression
	: multiplicative_expression				{ $$ = $1; }
	| additive_expression '+' multiplicative_expression	{ $$ = new algebra(ADD, $1, $3 ); }
	| additive_expression '-' multiplicative_expression	{ $$ = new algebra(SUB, $1, $3 ); }
	;

shift_expression
	: additive_expression					{ $$ = $1; }
	| shift_expression LEFT_OP additive_expression		{ $$ = new algebra(LEFT_, $1, $3 ); }
	| shift_expression RIGHT_OP additive_expression		{ $$ = new algebra(RIGHT_, $1, $3 ); }
	;

relational_expression
	: shift_expression					{ $$ = $1; }
	| relational_expression '<' shift_expression		{ $$ = new algebra(SMALLER, $1, $3 ); }
	| relational_expression '>' shift_expression		{ $$ = new algebra(GREATER, $1, $3 ); }
	| relational_expression LE_OP shift_expression		{ $$ = new algebra(LE_, $1, $3 ); }
	| relational_expression GE_OP shift_expression		{ $$ = new algebra(GE_, $1, $3 ); }
	;

equality_expression
	: relational_expression					{ $$ = $1; }
	| equality_expression EQ_OP relational_expression	{ $$ = new algebra(EQ_, $1, $3 ); }
	| equality_expression NE_OP relational_expression	{ $$ = new algebra(NE_, $1, $3 ); }
	;

and_expression
	: equality_expression					{ $$ = $1; }
	| and_expression '&' equality_expression		{ $$ = new algebra(AND, $1, $3 ); }
	;

exclusive_or_expression
	: and_expression					{ $$ = $1; }
	| exclusive_or_expression '^' and_expression		{ $$ = new algebra(XOR, $1, $3 ); }
	;

inclusive_or_expression
	: exclusive_or_expression				{ $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression	{ $$ = new algebra(OR, $1, $3 ); }
	;

logical_and_expression
	: inclusive_or_expression				{ $$ = $1; }
	| logical_and_expression AND_OP inclusive_or_expression	{ $$ = new algebra(AND_, $1, $3 ); }
	;

logical_or_expression
	: logical_and_expression				{ $$ = $1; }
	| logical_or_expression OR_OP logical_and_expression	{ $$ = new algebra(OR_, $1, $3 ); }
	;

conditional_expression
	: logical_or_expression							{ $$ = new conditional_expression($1); }
	| logical_or_expression '?' expression ':' conditional_expression	{ $$ = new conditional_expression($1, $3, $5); }
	;

assignment_expression
	: conditional_expression					{ $$ = new assignment_expression($1); }
	| unary_expression assignment_operator assignment_expression	{ $$ = new assignment_expression($1, $2, $3); }
	;

assignment_operator
	: '='		{ $$ = ASSIGN; }
	| MUL_ASSIGN	{ $$ = MULA; }
	| DIV_ASSIGN	{ $$ = DIVA; }
	| MOD_ASSIGN	{ $$ = MODA; }
	| ADD_ASSIGN	{ $$ = ADDA; }
	| SUB_ASSIGN	{ $$ = SUBA; }
	| LEFT_ASSIGN	{ $$ = LEFTA; }
	| RIGHT_ASSIGN	{ $$ = RIGHTA; }
	| AND_ASSIGN	{ $$ = ANDA; }
	| XOR_ASSIGN	{ $$ = XORA; }
	| OR_ASSIGN	{ $$ = ORA; }
	;

expression
	: assignment_expression			{ $$ = $1; }
	| expression ',' assignment_expression	{ $$ = new expression($1, $3); }
	;

constant_expression
	: conditional_expression	{ $$ = $1; }
	| declaration {$$ = $1;}
  ;

declaration
	: declaration_specifiers ';'				{ $$ = new declaration($1); }
	| declaration_specifiers init_declarator_list ';'	{ $$ = new declaration($1, $2); }
	;

declaration_specifiers
	: type_specifier					{ $$ = $1; }
	| type_specifier declaration_specifiers			{ $$ = new declaration_specifiers($1,$2); }
	| storage_class_specifier				{ $$ = $1; }
	| storage_class_specifier declaration_specifiers	{ $$ = new declaration_specifiers($1,$2); }
//	| type_qualifier					does not support type_qualifier
//	| type_qualifier declaration_specifiers			does not support type_qualifier
	;

init_declarator_list
	: init_declarator				{ $$ = $1; }
	| init_declarator_list ',' init_declarator	{ $$ = new init_declarator_list($1, $3); }
	;

init_declarator
	: declarator			{ $$ = new init_declarator($1); }
	| declarator '=' initializer	{ $$ = new init_declarator($1, $3); }
	;

storage_class_specifier
	: TYPEDEF		{ $$ = new storage_class_specifier(0); }
	| EXTERN		{ $$ = new storage_class_specifier(1); }
//	| STATIC		{/*not in use*/}
//	| AUTO			{/*not in use*/}
//	| REGISTER		{/*not in use*/}
	;

type_specifier
	: VOID				{ $$ = new type_specifier(0); }
	| CHAR				{ $$ = new type_specifier(1); }
	| SHORT  			{ $$ = new type_specifier(2); }
	| INT				  { $$ = new type_specifier(3); }
	| LONG				{ $$ = new type_specifier(4); }
	| FLOAT				{ $$ = new type_specifier(5); }
	| DOUBLE			{ $$ = new type_specifier(5); }
	| SIGNED			{ $$ = new type_specifier(7); }
	| UNSIGNED			{ $$ = new type_specifier(8); }
//	| struct_or_union_specifier	{ $$ = new type_specifier(9); }
//	| enum_specifier		{ $$ = new type_specifier(10); }
//	| TYPE_NAME			{ $$ = new type_specifier(11); }
	;
//
//struct_or_union_specifier
//	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
//	| struct_or_union '{' struct_declaration_list '}'
//	| struct_or_union IDENTIFIER
//	;
//
//struct_or_union
//	: STRUCT
////	| UNION {/*not in use*/}
//	;
//
//struct_declaration_list
//	: struct_declaration
//	| struct_declaration_list struct_declaration
//	;
//
//struct_declaration
//	: specifier_qualifier_list struct_declarator_list ';'
//	;
//
//specifier_qualifier_list
//	: type_specifier specifier_qualifier_list
//	| type_specifier
//	| type_qualifier specifier_qualifier_list
//	| type_qualifier
//	;
//
//struct_declarator_list
//	: struct_declarator
//	| struct_declarator_list ',' struct_declarator
//	;
//
//struct_declarator
//	: declarator
//	| ':' constant_expression
//	| declarator ':' constant_expression
//	;
//
//enum_specifier
//	: ENUM '{' enumerator_list '}'
//	| ENUM IDENTIFIER '{' enumerator_list '}'
//	| ENUM IDENTIFIER
//	;
//
//enumerator_list
//	: enumerator
//	| enumerator_list ',' enumerator
//	;
//
//enumerator
//	: IDENTIFIER
//	| IDENTIFIER '=' constant_expression
//	;

//type_qualifier
//	: CONST
//	| VOLATILE
//	;

declarator
	: direct_declarator		{ $$ = new declarator($1); }
//	| pointer direct_declarator	{ $$ = new declarator($1, $2); }
	;

direct_declarator
	: IDENTIFIER					{ $$ = new direct_declarator($1); }
	| '(' declarator ')'				{ $$ = new direct_declarator(1, $2); }
	| direct_declarator '[' constant_expression ']'	{ $$ = new direct_declarator(2, $1, $3); }
	| direct_declarator '[' ']'			{ $$ = new direct_declarator(3, $1); }
	| direct_declarator '(' parameter_type_list ')'	{ $$ = new direct_declarator(4, $1, $3); }
//	| direct_declarator '(' identifier_list ')'	// OLD KR style
	| direct_declarator '(' ')'			{ $$ = new direct_declarator(5, $1); }
	;

//pointer
//	: '*'
//	| '*' type_qualifier_list
//	| '*' pointer
//	| '*' type_qualifier_list pointer
	;

//type_qualifier_list
//	: type_qualifier
//	| type_qualifier_list type_qualifier
//	;


parameter_type_list
	: parameter_list	{ $$=$1; }
//	| parameter_list ',' ELLIPSIS {/*not in use*/}
	;

parameter_list
	: parameter_declaration				{ $$ = $1; }
	| parameter_list ',' parameter_declaration	{ $$ = new parameter_list($1, $3); }
	;

parameter_declaration
	: declaration_specifiers declarator		{ $$ = new parameter_declaration(0, $1, $2); }
//	| declaration_specifiers abstract_declarator
	| declaration_specifiers			{ $$ = new parameter_declaration($1); }
	;

////identifier_list
////	: IDENTIFIER
////	| identifier_list ',' IDENTIFIER
////	;
//

//type_name
//	: specifier_qualifier_list
//	| specifier_qualifier_list abstract_declarator;

//abstract_declarator
//	: pointer
//	| direct_abstract_declarator
//	| pointer direct_abstract_declarator
//	;
//
//direct_abstract_declarator
//	: '(' abstract_declarator ')'
//	| '[' ']'
//	| '[' constant_expression ']'
//	| direct_abstract_declarator '[' ']'
//	| direct_abstract_declarator '[' constant_expression ']'
//	| '(' ')'
//	| '(' parameter_type_list ')'
//	| direct_abstract_declarator '(' ')'
//	| direct_abstract_declarator '(' parameter_type_list ')'
//	;

initializer
	: assignment_expression		{ $$ = new initializer(0, $1); }
	| '{' initializer_list '}'	{ $$ = new initializer(1, $2); }
	| '{' initializer_list ',' '}'	{ $$ = new initializer(1, $2); }
	;

initializer_list
	: initializer				{ $$ = $1; }
	| initializer_list ',' initializer	{ $$ = new initializer_list($1, $3); }
	;

statement
	: labeled_statement	{ $$ = $1; }
	| compound_statement	{ $$ = $1; }
	| expression_statement	{ $$ = $1; }
	| selection_statement	{ $$ = $1; }
	| iteration_statement	{ $$ = $1; }
	| jump_statement	// NO jump statement
	;

labeled_statement
	: IDENTIFIER ':' statement			{ $$ = new labeled_statement(0, $3); }
	| CASE constant_expression ':' statement	{ $$ = new labeled_statement($2, $4); }
	| DEFAULT ':' statement				{ $$ = new labeled_statement(2, $3); }
	;

compound_statement
	: '{' '}'					{ $$ = new compound_statement(NULL, NULL);}
	| '{' statement_list '}'			{ $$ = new compound_statement(NULL, $2);}
	| '{' declaration_list '}'			{ $$ = new compound_statement($2, NULL);}
	| '{' declaration_list statement_list '}'	{ $$ = new compound_statement($2, $3);}
	;

declaration_list
	: declaration			{ $$ = $1; }
	| declaration_list declaration	{ $$ = new declaration_list($1, $2); }
	;

statement_list
	: statement			{ $$ = $1; }
	| statement_list statement	{ $$ = new statement_list($1, $2); }
	;

expression_statement
	: ';'			{ $$ = new expression_statement(); }
	| expression ';'	{ $$ = new expression_statement($1); }
	;

selection_statement
	: IF '(' expression ')' statement			{ $$ = new selection_statement(0, $3, $5); }
	| IF '(' expression ')' statement ELSE statement	{ $$ = new selection_statement($3, $5, $7); }
	| SWITCH '(' expression ')' statement			{ $$ = new selection_statement(2, $3, $5); }
	;

iteration_statement
	: WHILE '(' expression ')' statement						{ $$ = new iteration_statement(0, $3, $5 ); }
	| DO statement WHILE '(' expression ')' ';'					{ $$ = new iteration_statement(1, $2, $5 ); }
	| FOR '(' expression_statement expression_statement ')' statement		{ $$ = new iteration_statement($3, $4, $6 ); }
	| FOR '(' expression_statement expression_statement expression ')' statement	{ $$ = new iteration_statement($3, $4, $5, $7); }
	;

jump_statement
	: GOTO IDENTIFIER ';'	{ $$ = new jump_statement(0); }
	| CONTINUE ';'		{ $$ = new jump_statement(1); }
	| BREAK ';'		{ $$ = new jump_statement(2); }
	| RETURN ';'		{ $$ = new jump_statement(3); }
	| RETURN expression ';'	{ $$ = new jump_statement(4, $2); }
	;

top
	: translation_unit { g_root=$1; }

translation_unit
	: external_declaration			{ $$ = $1; }
	| translation_unit external_declaration	{ $$ = new translation_unit($1, $2); }
	;

external_declaration
	: function_definition	{ $$ = new external_declaration(0, $1); }
	| declaration		{ $$ = new external_declaration(1, $1); }
	;

function_definition
	: declaration_specifiers declarator compound_statement			{ $$ = new function_definition($1,$2,$3); }
	| declarator compound_statement						{ $$ = new function_definition($1,$2); }
//	| declaration_specifiers declarator declaration_list compound_statement	//KR style
//	| declarator declaration_list compound_statement			//KR style
	;

%%

const ast_abs * g_root;

const ast_abs * parseAST(void)
{
  g_root=0;
  yyparse();
  return g_root;
}
