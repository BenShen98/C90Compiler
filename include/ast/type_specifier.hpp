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

    std::string c()const override{
      switch(type){
        case 0:
        return "void";
        case 1:
        return "char";
        case 2:
        return "short";
        case 3:
        return "int";
        case 4:
        return "long";
        case 5:
        return "float";
        case 6:
        return "double";
        case 7:
        return "signed";
        case 8:
        return "unsigned";
        case 9:
        return "struct";
      }
    }
};

#endif
