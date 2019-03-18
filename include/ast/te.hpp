#ifndef ast_te
#define ast_te

#include <string>
#include <iostream>
#include "_ast_abs.hpp"

class te: public ast_abs{
    std::string str;


public:
    te(std::string rx):str(rx){}
    ~te()override{}


    void py(std::string& dst) const override{
        dst=str;
    }

    void mp(Result& result) const override{
        std::cout<<str;
    }


};

#endif
