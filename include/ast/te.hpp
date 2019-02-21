#ifndef te_x
#define te_x

#include <string>
#include <iostream>
#include "_expression.hpp"

class te: public expression{
    std::string str;


public:
    te(std::string rx):str(rx){}


    void py(std::string& dst) const override{
        dst=str;
    }

    void mp() const override{
        std::cout<<str;
    }


};

#endif
