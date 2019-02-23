#ifndef ast_external_declaration
#define ast_external_declaration

#include "_ast_abs.hpp"

/*
external_declaration
	: function_definition
	| declaration
	;
 */

class external_declaration: public ast_abs{
    int type;
    astPtr data;

public:
    external_declaration(int t, astPtr d):type(t),data(d){}

    ~external_declaration() override{
        delete data;
    }

    void py(std::string& dst) const override{
        data->py(dst);

    }

    void mp() const override{
        switch (type){


            default:
                notImplemented();
        }
    }

};

#endif
