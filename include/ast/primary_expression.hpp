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
inline StackId cConst2Mp(std::string cConst);


class primary_expression: public ast_abs{
private:
    int type;

    // make a union for two type below
    astPtr pt=0;
    std::string * str;



public:
    primary_expression(int t,std::string * s):type(t),str(s){}   //for type 0,1,2
    primary_expression(int t, astPtr p):type(t),pt(p){}         //for type 3


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

    void mp(Result& result) const override{

        switch (type){
            case 0:
                //use void to refer it's not a variable
                if(isVoid(result.type)) {
                    //void flag, need str
                    result.str=*str;
                }else{
                    // load variable, may be referenced latter
                    result.id = mips.getId(*str);
                    result.freeable = false;
                }
                break;

            case 1: //char, int, float

                if(isVoid(result.type)){
                    result.num = std::stoll(*str,0,0);  //return dec, compile time constant
                }else{
                    result.id = cConst2Mp(*str); //return stack id, imm in register
                }


                //its a letral
                result.freeable = true;
                break;

            case 2://string literal
                notImplemented();
                break;

            case 3:
                //evaluate the expression
                pt->mp(result);

                // make temporary duplicate,
//                result.id=mips.reserveId(sizeOf(rst.type),rst.type,"temp copy of "+ rst.id.str(),);
//                mips.assignment(result.id,rst.id,ASSIGN,rst.freeable);
//                result.freeable=true;

                //pass on to parents
                break;

        }
    }

};

inline std::string cConst2pyConst(std::string cConst){

    if( cConst[0]=='0' ){
        // input is either oct(0467), hex(0x2af), binary(0b0101)
        if( isDec(cConst[1]) ){
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

// return id which stored the constant
inline StackId cConst2Mp(std::string cConst){
    // convert string to what ever

    //TODO: float,
    //TODO: CHECK WITH SPEC 6.3 Conversions

    switch (cConst[0]){
        case '\'': //char literal
            notImplemented();
            break;
        case 'f': //false
            notImplemented();
            break;
        case 't':
            notImplemented();
            break;

        case '0':
                return ( mips.immediate(4, std::to_string(std::stoll(cConst,0,0)), TYPE_SIGNED_INT ,"imm "+ cConst ) );


        default:
            //integer/ floating point decimal literal
            // possible postfix : u,U ,f,F
        {
            auto dot=cConst.find('.');
            auto exp=cConst.find('e');

            if( dot==std::string::npos && exp==std::string::npos) {
                // input does not contain . nor e
                    return ( mips.immediate(4, std::to_string(std::stoll(cConst,0,0)), TYPE_SIGNED_INT ,"imm "+ cConst ) );

            } else{
                //floating point
                notImplemented();

//                type=TYPE_DOUBLE_FLOAT;
//                if( cConst.back()=='F' || cConst.back()='f' ) {
//                    setUnsignedInt(type);
//                    cConst.pop_back(); //remove postfix
//                }
            }


            break;
        }
    }

    return {-1,-1}; //remove warning
}


#endif
