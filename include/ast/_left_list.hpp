#ifndef ast_left_associative_list
#define ast_left_associative_list

#include "_ast_abs.hpp"

/*
 * left associative list
LIST
	: LIST
	| LIST ELEMENT
	;
 */

class left_list: public ast_abs{
    astPtr list=0;   //can only be translation_unit
    astPtr element;    //can only be external_declaration

public:
    left_list(astPtr l, astPtr e):list(l),element(e){}
    left_list(astPtr e):element(e){}

    ~left_list() override{
        delete list;
        delete element;
    }

    virtual void py(std::string& dst) const override{
        std::string e, l;
        element->py(e);

        if(list!=NULL){
            list->py(l);
            dst = l + '\n' + e;
        }else{
            dst=e;
        }



    }

    virtual void mp() const override{
        notImplemented();
    }

};

#endif
