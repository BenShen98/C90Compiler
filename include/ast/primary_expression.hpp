#ifndef ast_primary_expression
#define ast_primary_expression

#include "_ast_abs.hpp"
#include <string>
/*
primary_expression      (IDENTIFIER does not contain "", but STRING_LITERAL does)
0	: IDENTIFIER
1	| CONSTANT
2	| STRING_LITERAL            the string itself should contain `""`, as passed from yacc
3	| '(' expression ')'
	;
 */


inline bool isDec(char c) { return (c>='0' && c<='9'); }
inline std::string cConst2pyConst(std::string cConst);

class primary_expression: public ast_abs{
    int type;

    // make a union for two type below
    astPtr pt=0;
    const std::string *str;


public:
    primary_expression(int t,const std::string *s):type(t),str(s){ std::cerr<< "primary_expression type0,1,2 | get"<< t<<"\n"; }   //for type 0,1,2
    primary_expression(int t, astPtr p):type(t),pt(p){ std::cerr<< "primary_expression type3 | get"<< t<<"\n"; }         //for type 3


    ~primary_expression() override{
        delete pt;
        delete str;
    }

    void py(std::string& dst) const override{
        switch (type){
            case 0: //IDENTIFIER
                dst=*str;
                break;

            case 1: //constant
                dst=cConst2pyConst(*str);
                break;

            case 2: //string
                dst=*str;
                break;

            case 3: //expression
                std::string s;
                pt->py(s);
                dst = '(' + s + ')';
                break;
        }

    }

    void mp() const override{
        switch (type){

            default:
                notImplemented();
        }
    }

};

inline std::string cConst2pyConst(std::string cConst){

    if( cConst[0]=='0' ){
        // input is either oct(0467), hex(0x2af), binary(0b0101)
        if( !isDec(cConst[1]) ){
            //input is oct, change format from 0467 to 0o467
            cConst.insert(1,1,'o');
        }
    }

    //remove postfix is exist
    while ( !isDec(cConst.back()) ){
        cConst.pop_back();
    }

    return cConst;

}


#endif
