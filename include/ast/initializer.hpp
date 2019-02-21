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
        notImplemented();
    }

    void mp() const override{
        notImplemented();

    }

};

#endif