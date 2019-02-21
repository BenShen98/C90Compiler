#ifndef ast_translation_unit
#define ast_translation_unit

#include "_expression.hpp"

/*
translation_unit
	: external_declaration
	| translation_unit external_declaration
	;
 */

class translation_unit: public expression{
    astPtr _unit=0;   //can only be translation_unit
    astPtr _declaration;    //can only be external_declaration

public:
    translation_unit(astPtr l, astPtr r):_unit(l),_declaration(r){}
    translation_unit(astPtr r):_declaration(r){}


    ~translation_unit() override{
        delete _unit;
        delete _declaration;
    }

    void py(std::string& dst) const override{
        std::string declaration, unit;
        _declaration->py(declaration);

        if(_unit!=0){
            _declaration->py(unit);
            dst = unit + '\n' + declaration;
        }else{
            dst = declaration;
        }
    }

    void mp() const override{
        _unit->mp();
        _declaration->mp();
    }

};

#endif
