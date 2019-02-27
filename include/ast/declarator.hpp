#ifndef ast_declarator
#define ast_declarator

#include "_ast_abs.hpp"
#include <iostream>
/*
declarator
0	: pointer direct_declarator
1	| direct_declarator
	;
 */

class declarator: public ast_abs{
    astPtr pointer;
    astPtr direct_declarator;

public:
    declarator(astPtr t, astPtr d):pointer(t),direct_declarator(d){}
    declarator(astPtr d):pointer(0),direct_declarator(d){}

    ~declarator() override{
        delete pointer;
        delete direct_declarator;
    }

    void py(std::string& dst) const override{
        if(pointer==NULL){
            //case 1, direct_declarator
            direct_declarator->py(dst);
        }else{
            //case 0, pointer direct_declarator
            std::cerr<<"Python does not support pointer\n";
            notImplemented();
        }
    }

    void mp() const override{
        notImplemented();
        if(pointer==0){
            //case 1, direct_declarator

        }else{
            //case 0, pointer direct_declarator

        }
    }

};

#endif
