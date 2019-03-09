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
                dst = "while " + c + ":\n" + s;
                break;

            default:
                notImplemented();
                break;
        }

    }

    void mp() const override{
        notImplemented();
    }

};

#endif
