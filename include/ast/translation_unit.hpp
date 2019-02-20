#ifndef ast_translation_unit
#define ast_translation_unit

#include "_expression.hpp"

class translation_unit: public expression{
    astPtr right;
    astPtr left;

public:
    translation_unit(astPtr r, astPtr l):right(r),left(l){}

    ~translation_unit() override{
        delete right;
        delete left;
    }

    void py(std::string& dst) const override{
        right->py(dst);
        left->py(dst);
    }

    void mp() const override{
        right->mp();
        left->mp();
    }

};

#endif
