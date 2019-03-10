#ifndef ast_left_associative_list
#define ast_left_associative_list

#include "_ast_abs.hpp"

/*
 * left associative list
LIST
X	: ELEMENT {$$=$1}
	| LIST ELEMENT
	;
 */

class left_list: public ast_abs{
protected:
    astPtr list=0;
    astPtr element;

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

        list->py(l);
        dst = l + ',' + e;

    }


    virtual void mp(Result& result) const override{
        list->mp(result);
        element->mp(result);
    }

    virtual void mp() const override{
        list->mp();
        element->mp();
    }

};

#endif
