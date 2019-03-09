#ifndef ast_parameter_declaration
#define ast_parameter_declaration

#include "_ast_abs.hpp"
#include <string>
/*
parameter_declaration
0	: declaration_specifiers declarator
1	| declaration_specifiers abstract_declarator
2	| declaration_specifiers
	;
 */



class parameter_declaration: public ast_abs{
    int type;
    astPtr declaration_specifiers;
    astPtr declarator=0;


public:
    parameter_declaration(astPtr p):type(2),declaration_specifiers(p){} //case 2
    parameter_declaration(int t, astPtr s, astPtr d):type(t),declaration_specifiers(s), declarator(d){} //case 1,2



    ~parameter_declaration() override{
        delete declaration_specifiers;
        delete declarator;
    }

    void py(std::string& dst) const override{

        switch (type){
            case 0:
                declarator->py(dst);
                break;

            case 1: //abstract_declarator
                notImplemented();
                break;

            case 2: //only declared types
                //DO NOTHING
                break;

        }

    }

    void mp() const override{
        switch (type){

            default:
                notImplemented();
        }
    }

};



#endif
