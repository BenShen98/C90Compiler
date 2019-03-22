//
// Created by Ben Shen on 2019-03-15.
//

#ifndef C90_CONTEXT_TYPE_HPP
#define C90_CONTEXT_TYPE_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <bitset>


#include "Mp_Type.hpp"



typedef struct _para{
    Type type;
    std::string name;
} Para;

typedef std::vector<Para> Paras;


typedef std::unordered_map<std::string, Paras> Functions;

inline std::ostream& operator << (std::ostream& os, const Paras v)
{
    Paras::const_iterator i = v.begin();
    os << "\treturn:: "<< (i->name) << '<'<< std::bitset<32>(i->type)<<'>';
    ++i;
    os << "\n\tpara:: \t\t\t";
    for ( ; i != v.end(); ++i)
    {
        os <<(i->name) <<'<'<< std::bitset<32>(i->type)<<">\n\t\t\t ";
    }
    return os;
}


#endif