#ifndef ast_translation_unit
#define ast_translation_unit

#include "_left_list.hpp"

/*
translation_unit
	: external_declaration
	| translation_unit external_declaration
	;
 */

class translation_unit: public left_list{
//    astPtr _unit=0;   //can only be translation_unit
//    astPtr _declaration;    //can only be external_declaration
//
public:
    translation_unit(astPtr l, astPtr e)
        :left_list(l,e){}

    translation_unit(astPtr e)
        :left_list(e){}
//
//
//    ~translation_unit() override{
//        delete _unit;
//        delete _declaration;
//    }
//
//    void py(std::string& dst) const override{
//        std::string declaration, unit;
//        _declaration->py(declaration);
//
//        if(_unit!=0){
//            _declaration->py(unit);
//            dst = unit + '\n' + declaration;
//        }else{
//            dst = declaration;
//        }
//    }
//
//    void mp() const override{
//        _unit->mp();
//        _declaration->mp();
//    }
std::string c()const override{
  if(list!=NULL){
    return list->c() + "," + element->c();
  }
  else{
    return element->c();
  }
}
};

#endif
