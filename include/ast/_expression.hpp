#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include <sstream>

class expression;

typedef const expression *astPtr;

class expression
{
public:
    virtual ~expression()
    {}

    //! Tell and expression to print itself to the given stream
//    virtual void print(std::ostream &dst) const =0;

    //! convert ast to python
    virtual void py(std::string& dst) const
    { throw std::runtime_error("Not implemented."); }

    virtual void mp() const
    { throw std::runtime_error("Not implemented."); }
};


#endif
