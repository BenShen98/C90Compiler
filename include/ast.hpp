
#ifndef NULL
#define NULL 0
#endif


#ifndef ast_hpp
#define ast_hpp


#include "ast/algebra.hpp"
#include "ast/assignment_expression.hpp"
#include "ast/_ast_abs.hpp"
#include "ast/compound_statement.hpp"
#include "ast/conditional_expression.hpp"
#include "ast/declaration.hpp"
#include "ast/declaration_list.hpp"
#include "ast/declarator.hpp"
#include "ast/direct_declarator.hpp"
#include "ast/expression.hpp"
#include "ast/expression_statement.hpp"
#include "ast/external_declaration.hpp"
#include "ast/function_definition.hpp"
#include "ast/init_declarator.hpp"
#include "ast/init_declarator_list.hpp"
#include "ast/initializer.hpp"
#include "ast/iteration_statement.hpp"
#include "ast/jump_statement.hpp"
#include "ast/_left_list.hpp"
#include "ast/primary_expression.hpp"
#include "ast/selection_statement.hpp"
#include "ast/statement.hpp"
#include "ast/statement_list.hpp"
#include "ast/te.hpp"
#include "ast/translation_unit.hpp"



extern const ast_abs * parseAST();

#endif
