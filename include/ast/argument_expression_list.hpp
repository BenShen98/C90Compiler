#ifndef ast_argument_expression_list
#define ast_argument_expression_list

#include "_left_list.hpp"

/*
argument_expression_list
: assignment_expression
| argument_expression_list ',' assignment_expression
;
*/

class argument_expression_list: public left_list{

public:
  argument_expression_list(astPtr l, astPtr e)
  :left_list(l,e){}

  argument_expression_list(astPtr e)
  :left_list(e){}

std::string c() const override{
    if(list!=NULL){
      return list->c() + "," + element->c();
    }else{
      return element->c();
    }
  }

};

#endif
