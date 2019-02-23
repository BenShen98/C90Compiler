#ifndef ast_direct_declarator
#define ast_direct_declarator

#include "_ast_abs.hpp"
#include <string>
/*
direct_declarator
0	: IDENTIFIER                                        DONE
1	| '(' declarator ')'                                DONE
2	| direct_declarator '[' constant_expression ']'
2	| direct_declarator '[' ']'
3	| direct_declarator '(' parameter_type_list ')'     (K&R-style ?)
3	| direct_declarator '(' identifier_list ')'
3	| direct_declarator '(' ')'                         DONE
	;
	;
 */

class direct_declarator: public ast_abs{
    int type;
    astPtr right;

    //only one of below is active, change to union (need  user-defineddestructors)
    std::string identifier;
    astPtr left;

public:
    direct_declarator(std::string id):type(0),identifier(id){}              //for case 0
    direct_declarator(astPtr declarator):type(1),left(declarator){}        //for case 1
    direct_declarator(int t, astPtr declarator, astPtr identifier_list):type(t),left(declarator),right(identifier_list){}   //for case 2,3


    ~direct_declarator() override{
        delete right;
        delete left;
    }

    void py(std::string& dst) const override{
        std::string s;
        switch (type){
            case 0: //IDENTIFIER
                dst=identifier;
                break;
            case 1:
                right->py(s);
                dst = '(' + s + ')';
            case 3:
                if(right==0){   //direct_declarator '(' ')'
                    left->py(s);
                    dst = s + "()";
                }else{
                    notImplemented();
                }
                break;
            default:
                notImplemented();
        }

    }

    void mp() const override{
        switch (type){

            default:
                notImplemented();
        }
    }

};

#endif
