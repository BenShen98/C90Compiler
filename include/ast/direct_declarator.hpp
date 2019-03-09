#ifndef ast_direct_declarator
#define ast_direct_declarator

#include "_ast_abs.hpp"
#include <string>
/*
direct_declarator
0	: IDENTIFIER
1	| '(' declarator ')'
2	| direct_declarator '[' constant_expression ']'
3	| direct_declarator '[' ']'
4	| direct_declarator '(' parameter_type_list ')'
X	| direct_declarator '(' identifier_list ')'         (K&R-style) REMOVED
5	| direct_declarator '(' ')'
	;
	;
 */

class direct_declarator: public ast_abs{
    int type;

    //only one of below is active, change to union (need  user-defineddestructors)
    std::string * identifier;
    astPtr left;

    astPtr right;

public:
    direct_declarator(std::string * id):type(0),identifier(id){}              //for case 0
    direct_declarator(int t, astPtr declarator):type(t),left(declarator){}        //for case 1,3,5
    direct_declarator(int t, astPtr declarator, astPtr identifier_list):type(t), left(declarator),right(identifier_list){}   //for case 2,4


    ~direct_declarator() override{
        delete right;
        delete left;
        delete identifier;
    }

    void py(std::string& dst) const override{
        std::string s,s_opt;


        switch (type){
            case 0: //variable deceleration
                dst=*identifier;
                break;
            case 1: //function deceleration WITHOUT prototype
                left->py(s);
                dst = '(' + s + ')';
                break;

            case 4:
                left->py(s);
                right->py(s_opt);
                dst = s + '(' + s_opt + ')';
                break;

            case 5:
                left->py(s);
                dst = s + "()";
                break;

            default:
                std::cerr<<"direct_declarator default case\n";
                notImplemented();
        }

    }

    enum_declarator_type query_declarator_type() const override{
        if( type==2 || type==3 ){
            return ARRAY;
        } else if( type==4 || type==5 ){
            return FUNC;
        } else{
            return OTHER;
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
