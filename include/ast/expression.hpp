#ifndef ast_expression
#define ast_expression

#include "_left_list.hpp"

/*
expression
	: assignment_expression
	| expression ',' assignment_expression
	;
 */

class expression: public left_list{
protected:
  astPtr l;
  astPtr e;

public:
    expression(astPtr l, astPtr e)
        :left_list(l,e){}

    expression(astPtr e)
        :left_list(e){}

    std::string c()const override{
      if(list!=NULL){
        return list->c() + ',' + element->c();
      }
      else{
        return element->c();
      }
    }

};

#endif
