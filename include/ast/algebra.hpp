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

enum enum_algebra {MUL,DIV,MOD ,ADD,SUB, LEFT_,RIGHT_, SMALLER,GREATER, LE_,GE_,EQ_,NE_, AND,XOR,OR, AND_,OR_, };

class algebra: public ast_abs{
    enum_algebra type;
    astPtr left;
    astPtr right;

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

            case LEFT_:
                dst = '(' +  l + "<<" + r + ')';
                break;

            case RIGHT_:
                dst = '(' +  l + ">>" + r + ')';
                break;

            case SMALLER:
                dst = '(' +  l + '<' + r + ')';
                break;

            case GREATER:
                dst = '(' +  l + '>' + r + ')';
                break;

            case LE_:
                dst = '(' +  l + "<=" + r + ')';
                break;

            case GE_:
                dst = '(' +  l + ">=" + r + ')';
                break;

            case EQ_:
                dst = '(' +  l + "==" + r + ')';
                break;

            case NE_:
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

            case AND_:
                dst = '(' +  l + "and" + r + ')';
                break;

            case OR_:
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

            case LEFT_:
                break;

            case RIGHT_:
                break;

            case SMALLER:
                break;

            case GREATER:
                break;

            case LE_:
                break;

            case GE_:
                break;

            case EQ_:
                break;

            case NE_:
                break;

            case AND:
                break;

            case XOR:
                break;

            case OR:
                break;

            case AND_:
                //short circuit
                break;

            case OR_:
                //short circuit
                break;
        }
    }

};

#endif
