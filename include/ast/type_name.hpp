#ifndef type_name_hpp
#define type_name_hpp

#include "_ast_abs.hpp"
#include <bitset>

/*
type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator;
 */

class type_name: public ast_abs{
    astPtr specifier_qualifier_list;
    astPtr abstract_declarator=0;

public:
    type_name(astPtr d, astPtr i):specifier_qualifier_list(d),abstract_declarator(i){}
    type_name(astPtr d):specifier_qualifier_list(d){}


    ~type_name() override{
        delete specifier_qualifier_list;
        delete abstract_declarator;
    }

    void mp(Result& result) const override{
        Result declareType;
        specifier_qualifier_list->mp(result);

        if(abstract_declarator!=NULL)
            abstract_declarator->mp(result);



    }

};

#endif
