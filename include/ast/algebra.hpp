#ifndef ast_algebra
#define ast_algebra

#include "_ast_abs.hpp"
#include "algebra_enum.hpp"

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
      dst = '(' +  l + '&' + r +  ')';
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

  virtual std::string c() const override {
    switch (type) {
      //brackets are redundant but just in case
      case MUL:
      return '(' +  left->c() + '*' + right->c() + ')';
      break;

      case DIV:
      return  '(' +  left->c()+ '/' + right->c()+ ')';
      break;

      case MOD:
      return  '(' +  left->c()+ '%' + right->c()+ ')';
      break;

      case ADD:
      return  '(' +  left->c()+ '+' + right->c()+ ')';
      break;

      case SUB:
      return  '(' +  left->c()+ '-' + right->c()+ ')';
      break;

      case LEFT_:
      return  '(' +  left->c()+ "<<" + right->c()+ ')';
      break;

      case RIGHT_:
      return  '(' +  left->c()+ ">>" + right->c()+ ')';
      break;

      case SMALLER:
      return  '(' +  left->c()+ '<' + right->c()+ ')';
      break;

      case GREATER:
      return  '(' +  left->c()+ '>' + right->c()+ ')';
      break;

      case LE_:
      return  '(' +  left->c()+ "<=" + right->c()+ ')';
      break;

      case GE_:
      return  '(' +  left->c()+ ">=" + right->c()+ ')';
      break;

      case EQ_:
      return  '(' +  left->c()+ "==" + right->c()+ ')';
      break;

      case NE_:
      return  '(' +  left->c()+ "!=" + right->c()+ ')';
      break;

      case AND:
      return  '(' +  left->c()+ '&' + right->c()+ ')';
      break;

      case XOR:
      return  '(' +  left->c()+ '^' + right->c()+ ')';
      break;

      case OR:
      return  '(' +  left->c()+ '|' + right->c()+ ')';
      break;

      case AND_:
      return  '(' +  left->c()+ "and" + right->c()+ ')';
      break;

      case OR_:
      return  '(' +  left->c()+ "or" + right->c()+ ')';
      break;
    }
  }

  virtual void mp(Result& para) const override{
    int resultId=para.id;
    int resultType=para.type;

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
