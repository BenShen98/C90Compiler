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
    int ptrCount;
    astPtr direct_declarator;

public:
    declarator(int t, astPtr d):ptrCount(t),direct_declarator(d){}
    declarator(astPtr d):ptrCount(0),direct_declarator(d){}

    ~declarator() override{
        delete direct_declarator;
    }

    void py(std::string& dst) const override{
        if(ptrCount==0){
            //case 1, direct_declarator
            direct_declarator->py(dst);
        }else{
            //case 0, pointer direct_declarator
            std::cerr<<"Python does not support pointer\n";
            notImplemented();
        }
    }

    enum_declarator_type query_declarator_type() const override{
        return direct_declarator->query_declarator_type();
    }

    void mp(Result& para) const override{
        if(ptrCount==0){
            //case 1, direct_declarator
            direct_declarator->mp(para);

        }else{
            para.addr.insert(para.addr.end(), ptrCount, -1);
            setAddressFlag(para.type);
            direct_declarator->mp(para);
            //case 0, pointer direct_declarator

        }
    }

};

#endif
