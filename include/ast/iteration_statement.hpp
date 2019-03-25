#ifndef ast_iteration_statement
#define ast_iteration_statement

#include "_left_list.hpp"

/*
iteration_statement
0	: WHILE '(' expression ')' statement
1	| DO statement WHILE '(' expression ')' ';'
2	| FOR '(' expression_statement expression_statement ')' statement
3	| FOR '(' expression_statement expression_statement expression ')' statement
	;
 */

class iteration_statement: public ast_abs{
    int type;
    astPtr init=0;
    astPtr condition; //ONLY iterate when condition is true
    astPtr increment=0;
    astPtr statement;

public:
    iteration_statement(int t, astPtr c, astPtr s): type(t), condition(c), statement(s){} //case 0 1
    iteration_statement(astPtr i, astPtr c, astPtr s): type(2),init(i), condition(c), statement(s){} //case2
    iteration_statement(astPtr i, astPtr c, astPtr  inc, astPtr s): type(3),init(i), condition(c), increment(inc), statement(s){} //case3

    ~iteration_statement() override{
        delete init;
        delete condition;
        delete increment;
        delete statement;
    }

    void py(std::string& dst) const override{
        std::string c,s;
        condition->py(c);
        statement->py(s);
        indent(s);

        switch (type){
            case 0:
                dst = "while " + c + ":\n" + s +"\n\tpass";
                break;

            default:
                notImplemented();
                break;
        }

    }

    void mp() const override{

        //condition setup
        if(init!=NULL)
            init->mp();

        mips.writeBackAll();

        std::string condi=mips.mkLabel("ItrCondition");
        std::string end=mips.mkLabel("ItrEnd");

        //condition
        Result expResult;
        mips.insertLabel(condi);
        condition->mp(expResult); //condition is expression or expression_statement

        mips.bZero(false, expResult.id, end);
        statement->mp();

        if(type==1){// do while loop
            notImplemented();
        } else if(type==3){
            //for loop with post increment
            Result dummy;
            increment->mp(dummy);
        }

        mips.writeBackAll();


        //end of iteration
        mips.branch(condi);
        mips.insertLabel(end);
    }

};

#endif
