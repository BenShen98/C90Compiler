#ifndef ast_selection_statement
#define ast_selection_statement

#include "_left_list.hpp"

/*
selection_statement
0	: IF '(' expression ')' statement
1	| IF '(' expression ')' statement ELSE statement
2	| SWITCH '(' expression ')' statement
	;
 */

class selection_statement: public ast_abs{
    int type;
    astPtr exp;
    astPtr s1;
    astPtr s2=0;

public:
    selection_statement(int t, astPtr e, astPtr s): type(t), exp(e), s1(s){} //case 0 2
    selection_statement(astPtr e, astPtr _s1, astPtr _s2): type(1), exp(e), s1(_s1), s2(_s2) {} //case1



    ~selection_statement() override{
        delete exp;
        delete s1;
        delete s2;
    }

    void py(std::string& dst) const override{
        std::string e,s, s_false;
        exp->py(e);
        s1->py(s);
        indent(s);

        switch (type){
            case 0:
                dst = "if " + e + ":\n" + s;
                break;

            case 1:
                s2->py(s_false);
                indent(s_false);
                dst = "if " + e + ":\n" + s + "\nelse:\n" + s_false;
                break;

            case 2:
                notImplemented();
                break;
        }

    }

    void mp() const override{
        Result expResult;
        exp->mp(expResult);

        switch (type){
            case 0: //IF '(' expression ')' statement
            {
                std::string ifEnd=mips.mkLabel("ifEnd");

                mips.bZero(false, expResult.id, ifEnd); //skip s1 when false

                //gen code for s1
                mips.comment("true case for "+ifEnd);
                s1->mp(); // no para, is statement

                mips.insertLabel(ifEnd);


            }
                break;

            case 1: //IF '(' expression ')' statement ELSE statement
            {
              std::string elsestart=mips.mkLabel("elseStart");
              std::string elseend=mips.mkLabel("elseEnd");
              mips.bZero(false, expResult.id, elsestart); //skip s1 when false
              s1->mp();
              //gen code for s1
              //branch to end
              mips.branch(elseend);
              mips.insertLabel(elsestart);
              s2->mp();
              //gen code for s2
              mips.insertLabel(elseend);

            }
                break;

            case 2://SWITCH '(' expression ')' statement
            {
              // //TODO branching label
              // std::string label=mips.mkLabel("CaseEnd");
              // expResult.str=label;
              // s1->mp(expResult);
              //
              // //assign label to expResult.str
              // mips.insertLabel(label);
            }
              break;
        }
    }

};

#endif
