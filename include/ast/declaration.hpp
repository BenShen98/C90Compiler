#ifndef ast_declaration
#define ast_declaration

#include "_ast_abs.hpp"
#include <bitset>

/*CHECKED
declaration
	: declaration_specifiers ';' //USELESS? (unreachable, no effect)
	| declaration_specifiers init_declarator_list ';'
	;
 */

class declaration: public ast_abs{
    astPtr declaration_specifiers;
    astPtr init_declarator_list=0;

public:
    declaration(astPtr d, astPtr i):declaration_specifiers(d),init_declarator_list(i){}
    declaration(astPtr d):declaration_specifiers(d){}


    ~declaration() override{
        delete declaration_specifiers;
        delete init_declarator_list;
    }

    void py(std::string& dst) const override{
        //ignore type check, by spec only requires int variable
        if(init_declarator_list!=NULL){
            init_declarator_list->py(dst);
        }

    }

    void mp() const override{
        //get type
        if(init_declarator_list!=NULL){
            Result declareType;
            declaration_specifiers->mp(declareType);
            init_declarator_list->mp(declareType);
        }else{
            std::cerr<<"[warning], useless type name in empty declaration\n";
        }

    }

    void mp(Result r) const override{ //for global variable, str=="global"
        //get type
        if(init_declarator_list!=NULL){
            declaration_specifiers->mp(r);
            init_declarator_list->mp(r);
        }else{
            std::cerr<<"[warning], useless type name in empty declaration\n";
        }

    }

};

#endif
