#ifndef ast_declaration_specifiers
#define ast_declaration_specifiers

#include "_left_list.hpp"

/*
declaration_specifiers
	: storage_class_specifier
  | storage_class_specifier declaration_specifiers
  | type_specifier
  | type_specifier declaration_specifiers
  X	| type_qualifier
  X	| type_qualifier declaration_specifiers
  ;
  */

  class declaration_specifiers: public right_list{

  public:
    declaration_specifiers(astPtr e, astPtr l)
    :right_list(e,l){}

    declaration_specifiers(astPtr e)
    :right_list(e){}

    virtual std::string c()const override{
      if(list!=NULL){
        return element->c() + list->c();
      }
      else{
        return element->c();
      }
    }
  };

#endif
