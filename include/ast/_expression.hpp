#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include <sstream>

class expression;

typedef const expression *astPtr;
inline void notImplemented(){ throw std::runtime_error("Not implemented."); }

void indent(std::string& str){
    std::string::size_type pos = 0; // Must initialize
    str.insert ( pos, 1,'\t' );     // indent first line by \t
    while ( ( pos = str.find ('\n',pos+1) ) != std::string::npos ) // replace \n with \n\t
    {
        str.insert ( pos+1, 1,'\t' );
    }
}

class expression
{
public:
    virtual ~expression()
    {}

    //! Tell and expression to print itself to the given stream
//    virtual void print(std::ostream &dst) const =0;

    //! convert ast to python
    virtual void py(std::string& dst) const
    { notImplemented(); }

    virtual void mp() const
    { notImplemented(); }
};


#endif
