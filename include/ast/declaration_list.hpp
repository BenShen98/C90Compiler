#ifndef ast_declaration_list
#define ast_declaration_list

#include "_right_list.hpp"

/*
declaration_list
	: declaration
	| declaration_list declaration
	;
 */

class declaration_list: public left_list{
// protected:
//   astPtr l;
//   astPtr e;

public:
    declaration_list(astPtr l, astPtr e)
        :left_list(l,e){}

    declaration_list(astPtr e)
        :left_list(e){}

    virtual std::string c()const override{
      if(list != NULL){
        return list->c() + element->c();
      }
      else{
        return element->c();
      }
    }

};

#endif
