#ifndef ast_storage_class_specifier
#define ast_storage_class_specifier

#include "_ast_abs.hpp"

/*
storage_class_specifier
0	: TYPEDEF
1	| EXTERN
2	| STATIC
3	| AUTO
4	| REGISTER
	;
 */

class storage_class_specifier: public ast_abs{
    int type;


public:
    storage_class_specifier(int t):type(t){}
    ~storage_class_specifier()override{}


    void py(std::string& dst) const override{
        //python does not define type, skip
    }

    void mp(Result& result) const override{
        notImplemented();
    }


};

#endif
