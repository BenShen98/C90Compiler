#ifndef abstract_declarator_hpp
#define abstract_declarator_hpp

#include "_ast_abs.hpp"
#include <string>
/*
abstract_declarator
0	: pointer
1	| direct_abstract_declarator
2	| pointer direct_abstract_declarator
	;
 */

class abstract_declarator: public ast_abs{
    int type;

    astPtr direct=0;


public:
    abstract_declarator(int t):type(0){}
    abstract_declarator(int t, astPtr d):type(t),direct(d){}


    ~abstract_declarator() override{
        delete direct;
    }


    void mp(Result& result) const override{
        switch (type){
            case 0:
                result.addr.push_back(-1);
                break;

            case 1:
                direct->mp(result);
                break;

            case 2:
                result.addr.push_back(-1);
                direct->mp(result);
                break;

        }
    }

};

#endif
