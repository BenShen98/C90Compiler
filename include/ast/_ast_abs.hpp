#ifndef ast_abs_hpp
#define ast_abs_hpp

#include <string>
#include <iostream>
#include <sstream>
#include "_query_enum.hpp"
#include "../Type_mask.hpp"

class ast_abs;

typedef const ast_abs * astPtr;

inline void notImplemented(){ throw std::runtime_error("Not implemented."); }

inline void indent(std::string& str){
    std::string::size_type pos = 0; // Must initialize
    str.insert ( pos, 1,'\t' );     // indent first line by \t
    while ( ( pos = str.find ('\n',pos+1) ) != std::string::npos ) // replace \n with \n\t
    {
        str.insert ( pos+1, 1,'\t' );
    }
}

class ast_abs
{
public:
    virtual ~ast_abs()
    {}

    typedef struct _result{

        union{
            int id;     // used for operation which have dst register
            Type type; //used for declaration_specifiers
        };
        
        bool freeable=false;
    } Result;

    //! Tell and expression to print itself to the given stream
//    virtual void print(std::ostream &dst) const =0;

    /* convert ast to python
     *
     * dst should ONLY be used as return data
     */
    virtual void py(std::string& dst) const
    { notImplemented(); }

    /*
     * convert ast to MIPS
     *
     * result is used to pass back data
     * in SPECIAL CIRCUMSTANCE, it may also use as input variable.
     * However, it should be transparent to other class
     */
    virtual void mp(Result& result) const
    { notImplemented(); }


    virtual enum_declarator_type query_declarator_type() const {
        return OTHER;
    }
};


#endif
