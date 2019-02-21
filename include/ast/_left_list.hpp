#ifndef ast_left_associative_list
#define ast_left_associative_list

#include "_expression.hpp"

/*
 * left associative list
LIST
	: LIST
	| LIST ELEMENT
	;
 */

class left_list: public expression{
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
        element->py(l);

        if(list!=NULL){
            list->py(l);
        }

        dst = l + '\n' + e;

    }

    virtual void mp() const override{
        notImplemented();
    }

};

#endif
