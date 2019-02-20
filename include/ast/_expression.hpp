#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include <sstream>

class Expression;

typedef const Expression *ExpressionPtr;

class Expression
{
public:
    virtual ~Expression()
    {}

    //! Tell and expression to print itself to the given stream
    virtual void print(std::ostream &dst) const =0;

    //! convert ast to python
    virtual double python( ) const
    { throw std::runtime_error("Not implemented."); }

    virtual double mips( ) const
    { throw std::runtime_error("Not implemented."); }
};


#endif