#ifndef ast_compound_statement
#define ast_compound_statement

#include "_ast_abs.hpp"
#include <string>
/*CHECKED
compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;
 */

class compound_statement: public ast_abs{
    astPtr declaration_list=0;
    astPtr statement_list=0;

public:
    compound_statement(astPtr de, astPtr sta):declaration_list(de),statement_list (sta){}

    ~compound_statement() override{
        delete declaration_list;
        delete statement_list;
    }

    void py(std::string& dst) const override{
        std::string d,s;
       if(declaration_list!=NULL){
           declaration_list->py(d);
       }

       if(statement_list!=NULL){
           statement_list->py(s);
       }

       dst = d + '\n' + s;
    }

    void mp() const override{
        notImplemented();
    }

    virtual std::string c() const override{
      //case 3 4
      if(declaration_list!=NULL){
        if (statement_list!=NULL){
          return '{' + declaration_list->c() + statement_list->c() + '}';
        }
        else{
          return '{' + declaration_list->c() + '}';
        }
      }
      //case 1 2
      else{
        if (statement_list!=NULL){
          return '{' + statement_list->c() + '}';
        }
        else{
          return '{' + '}';
        }
      }
    }

};

#endif
