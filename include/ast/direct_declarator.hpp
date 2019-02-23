#ifndef ast_direct_declarator
#define ast_direct_declarator

#include "_ast_abs.hpp"
#include <string>
/*
direct_declarator
0	: IDENTIFIER
1	| '(' declarator ')'
2	| direct_declarator '[' constant_expression ']'
2	| direct_declarator '[' ']'
3	| direct_declarator '(' parameter_type_list ')'
X	| direct_declarator '(' identifier_list ')'         (K&R-style) REMOVED
3	| direct_declarator '(' ')'
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
        right->py(s);

        switch (type){
            case 0: //variable deceleration
                dst=identifier;
                break;
            case 1: //function deceleration WITHOUT prototype
                dst = '(' + s + ')';
                break;

            case 2: //array deceleration
                notImplemented();
                break;

            case 3:  //function deceleration (prototype) (NOT definition)
                //ignore all function deceleration in python
                //python DOES NOT support function deceleration
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

#endif
