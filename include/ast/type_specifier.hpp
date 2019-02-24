#ifndef ast_type_specifier
#define ast_type_specifier

#include "_ast_abs.hpp"

/*
type_specifier
0	: VOID
1	| CHAR
2	| SHORT
3	| INT
4	| LONG
5	| FLOAT
6	| DOUBLE
7	| SIGNED
8	| UNSIGNED
9	| struct_or_union_specifier
10	| enum_specifier
11	| TYPE_NAME
	;
 */

class type_specifier: public ast_abs{
    int type;


public:
    type_specifier(int t):type(t){}
    ~type_specifier()override{}


    void py(std::string& dst) const override{
        //python does not define type, skip
    }

    void mp() const override{
        notImplemented();
    }


};

#endif
