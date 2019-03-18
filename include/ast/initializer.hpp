#ifndef ast_initializer
#define ast_initializer

#include "_ast_abs.hpp"
/*
initializer
0	: assignment_expression
1	| '{' initializer_list '}'
1	| '{' initializer_list ',' '}'
	;

 */

class initializer: public ast_abs{
    int type;
    astPtr data;

public:
    initializer(int t, astPtr d):type(t),data(d){}

    ~initializer() override{
        delete data;
    }

    void py(std::string& dst) const override{
        if(type==0){
            data->py(dst);
        }else{
            notImplemented();
        }

    }

    void mp(Result& para) const override{
       if(type==0){
           Result op1;
            data->mp(op1);
            mips.assignment(para.id, op1.id,ASSIGN, op1.freeable);
       }else{
           notImplemented();
       }

    }

};

#endif
