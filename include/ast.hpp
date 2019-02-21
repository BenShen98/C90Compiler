
#ifndef NULL
#define NULL 0
#endif


#ifndef ast_hpp
#define ast_hpp


#include "ast/_expression.hpp"
#include "ast/translation_unit.hpp"
#include "ast/te.hpp"
#include "ast/external_declaration.hpp"
#include "ast/function_definition.hpp"






extern const expression * parseAST();

#endif
