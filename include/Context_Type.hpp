//
// Created by Ben Shen on 2019-03-15.
//

#ifndef C90_CONTEXT_TYPE_HPP
#define C90_CONTEXT_TYPE_HPP

#include <vector>
#include <string>
#include <unordered_map>

#include "Mp_Type.hpp"



typedef struct _para{
    Type type;
    std::string name;
} Para;

typedef std::vector<Para> Paras;


typedef std::unordered_map<std::string, Paras> Functions;




#endif