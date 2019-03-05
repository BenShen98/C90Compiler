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

public:
    declaration_list(astPtr l, astPtr e)
        :left_list(l,e){}

    declaration_list(astPtr e)
        :left_list(e){}

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
};

#endif
