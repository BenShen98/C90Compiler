#ifndef ast_type_specifier
#define ast_type_specifier

#include "_ast_abs.hpp"
#include <bitset>
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


    //python does not define type, skip

    void mp(Result& result) const override{
        std::cout<<"type "<<type<<" "<<std::bitset<32>(result.type)<<"\t";
        switch (type){
            //void
            case 0:
                setVoid(result.type);
                break;

            //int
            case 3:
                if( !isUnsignedInt(result.type) ){
                    //avoid overwrite unsigned int
                    setSignedInt(result.type);
                }
                break;
            case 7:
                setSignedInt(result.type);
                break;
            case 8:
                setUnsignedInt(result.type);
                break;

            //float
            case 5:
                setSingleFloat(result.type);
                break;
            case 6:
                setDoubleFloat(result.type);
                break;

            default:
                notImplemented();
        }
        std::cout<<std::bitset<32>(result.type)<<"\n";

    }


};

#endif
