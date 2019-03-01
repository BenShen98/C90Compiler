//
// Created by ben on 2019/3/1.
//

#ifndef C90_MP_HPP
#define C90_MP_HPP

#include <fstream>
#include <string>
extern std::ofstream ffout;

namespace mp{
    inline void add(std::string dst,std::string s, std::string t){
        ffout <<" ADD " << dst << ',' << s << ',' << t << '\n';
    }
}

#endif //C90_MP_HPP
