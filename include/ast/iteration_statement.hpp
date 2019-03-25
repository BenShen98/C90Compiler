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
        Result expResult;
        condition->mp(expResult);
        switch(type){
          case 0://WHILE '(' expression ')' statement
          {
            std::string start=mips.mkLabel("WhileStart");
            std::string end=mips.mkLabel("WhileEnd");
            mips.insertLabel(start);
            mips.bZero(false, expResult.id, end);
            statement->mp();
            mips.branch(start);
            mips.insertLabel(end);
          }
          break;
          case 1://DO statement WHILE '(' expression ')' ';'
          // {
          //   std::string start=mips.mkLabel("WhileStart");
          //   mips.insertLabel(start);
          //   statement->mp();
          //   mips.bZero(false, expResult.id, end);
          // }
          notImplemented();
          break;
          case 2: //FOR '(' expression_statement expression_statement ')' statement
          {
            std::string start=mips.mkLabel("ForStart");
            std::string end=mips.mkLabel("ForEnd");
            init->mp();
            mips.insertLabel(start);
            //branch on false
            mips.bZero(false, expResult.id, end);
            statement->mp();
            mips.branch(start);
            mips.insertLabel(end);
          }
          break;
          case 3://FOR '(' expression_statement expression_statement expression ')' statement
          {
            Result dummy;
            std::string start=mips.mkLabel("ForStart");
            std::string end=mips.mkLabel("ForEnd");
            init->mp();
            mips.insertLabel(start);
            //branch on false
            mips.bZero(false, expResult.id, end);
            //need dummy var here
            increment->mp(dummy);
            statement->mp();
            mips.branch(start);
            mips.insertLabel(end);
          }
          break;
        }
    }

};

#endif
