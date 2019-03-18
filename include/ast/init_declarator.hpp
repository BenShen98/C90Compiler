#ifndef ast_init_declarator
#define ast_init_declarator

#include "_ast_abs.hpp"
#include <iostream>
/*
init_declarator
	: declarator
	| declarator '=' initializer
 */

class init_declarator: public ast_abs{
    astPtr declarator;
    astPtr initializer=0;

public:
    init_declarator(astPtr d, astPtr i):declarator(d),initializer(i){}
    init_declarator(astPtr d):declarator(d){}


    ~init_declarator() override{
        delete declarator;
        delete initializer;
    }

    void py(std::string& dst) const override{
        std::string d,i;
        declarator->py(d);

        if(initializer==NULL){
            dst=d + "=0";
        }else{
            initializer->py(i);
            dst = d + '=' + i;
        }
    }

    enum_declarator_type query_declarator_type() const override{
        return declarator->query_declarator_type();
    }

    void mp(Result& para) const override{

        // pass down basic_type, return str,type
        declarator->mp(para);


        if(initializer==NULL){
            //zero init value
            mips.immediate(sizeOf(para.type), "0", para.type, para.str);

        }else{
            //pass id
            initializer->mp(para);

        }
    }

};

#endif
