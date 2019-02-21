#ifndef ast_algebra
#define ast_algebra

#include "_ast_abs.hpp"
#include <string>
/*
 * When there is only signal element in the tree, that element get promoted
 * e.g. multiplicative_expression:cast_expression  => {$$=$1}
 *
 *
multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

 */

enum enum_algebra {MUL,DIV,MOD ,ADD,SUB, LEFT_OP,RIGHT_OP, SMALLER,GREATER, LE_OP,GE_OP,EQ_OP,NE_OP, AND,XOR,OR, AND_OP,OR_OP, };

class algebra: public ast_abs{
    enum_algebra type;
    astPtr right;   //can only be translation_unit
    astPtr left;    //can only be external_declaration

public:
    algebra(enum_algebra t, astPtr l, astPtr r):type(t),left(l),right(r){}

    ~algebra() override{
        delete right;
        delete left;
    }

    virtual void py(std::string& dst) const override{
        std::string r,l;
        right->py(r);
        left->py(l);

        switch (type){
            //brackets are redundant but just in case
            case MUL:
                dst = '(' +  l + '*' + r + ')';
                break;

            case DIV:
                dst = '(' +  l + '/' + r + ')';
                break;

            case MOD:
                dst = '(' +  l + '%' + r + ')';
                break;

            case ADD:
                dst = '(' +  l + '+' + r + ')';
                break;

            case SUB:
                dst = '(' +  l + '-' + r + ')';
                break;

            case LEFT_OP:
                dst = '(' +  l + "<<" + r + ')';
                break;

            case RIGHT_OP:
                dst = '(' +  l + ">>" + r + ')';
                break;

            case SMALLER:
                dst = '(' +  l + '<' + r + ')';
                break;

            case GREATER:
                dst = '(' +  l + '>' + r + ')';
                break;

            case LE_OP:
                dst = '(' +  l + "<=" + r + ')';
                break;

            case GE_OP:
                dst = '(' +  l + ">=" + r + ')';
                break;

            case EQ_OP:
                dst = '(' +  l + "==" + r + ')';
                break;

            case NE_OP:
                dst = '(' +  l + "!=" + r + ')';
                break;

            case AND:
                dst = '(' +  l + '&' + r + ')';
                break;

            case XOR:
                dst = '(' +  l + '^' + r + ')';
                break;

            case OR:
                dst = '(' +  l + '|' + r + ')';
                break;

            case AND_OP:
                dst = '(' +  l + "and" + r + ')';
                break;

            case OR_OP:
                dst = '(' +  l + "or" + r + ')';
                break;
        }

    }

    virtual void mp() const override{
        notImplemented();

        switch (type){
            case MUL:
                break;

            case DIV:
                break;

            case MOD:
                break;

            case ADD:
                break;

            case SUB:
                break;

            case LEFT_OP:
                break;

            case RIGHT_OP:
                break;

            case SMALLER:
                break;

            case GREATER:
                break;

            case LE_OP:
                break;

            case GE_OP:
                break;

            case EQ_OP:
                break;

            case NE_OP:
                break;

            case AND:
                break;

            case XOR:
                break;

            case OR:
                break;

            case AND_OP:
                //short circuit
                break;

            case OR_OP:
                //short circuit
                break;
        }
    }

};

#endif
