#ifndef ast_init_declarator_list
#define ast_init_declarator_list

#include "_left_list.hpp"

/*
init_declarator_list
: init_declarator
| init_declarator_list ',' init_declarator
;
*/

class init_declarator_list: public left_list{
protected:
  astPtr l;
  astPtr e;

public:
  init_declarator_list(astPtr l, astPtr e)
  :left_list(l,e){}

  init_declarator_list(astPtr e)
  :left_list(e){}

  virtual std::string c()const override{
    if(list!=NULL){
      return list->c() + ',' + element->c();
    }
    else{
      return element->c();
    }
  }

};

#endif
