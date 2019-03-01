#ifndef ast_right_associative_list
#define ast_right_associative_list

#include "_ast_abs.hpp"

/*
 * right associative list
LIST
	: ELEMENT
	| ELEMENT LIST
	;
 */

class right_list: public ast_abs{
protected:
    astPtr element;
    astPtr list=0;

public:
    right_list(astPtr e, astPtr l):element(e), list(l){}
    right_list(astPtr e):element(e){}

    ~right_list() override{
        delete list;
        delete element;
    }

    virtual void py(std::string& dst) const override{
        std::string e, l;
        element->py(e);

        if(list!=NULL){
            list->py(l);
            dst = e + '\n' + l;
        }else{
            dst=e;
        }
    }

    virtual std::string c() const override{
      if(list!=NULL){
        return element->c() + list->c();
      }else{
        return element->c();
      }
    }

    virtual void mp() const override{
        notImplemented();
    }

};

#endif
