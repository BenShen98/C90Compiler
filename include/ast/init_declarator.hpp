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

    /*
     * //make a copy, DO NOT CHANGE basic_type, int x=5, *y, foo();
     */
    void mp(Result& para) const override{
        Result info=para;

        // pass down basic_type, return str,type
        declarator->mp(info);



        if(isAddressFlagSet(info.type)){
            // array deceleration
               info.id = mips.reserveArray(info.type, info.addr, info.str);

               if(initializer!=NULL){
                   initializer->mp(info);
               }

        }else if (!isVoid(info.type)){
            // basic type deceleration

            if(initializer==NULL){
                //zero init value
                mips.immediate(sizeOf(info.type), "0", info.type, info.str);

            }else{
                //pass id
                info.id=mips.reserveId(sizeOf(info.type),info.type,info.str);
                initializer->mp(info);

            }
        }else{
            //type is void, function deceleration, do nothing
        }


    }

};

#endif
