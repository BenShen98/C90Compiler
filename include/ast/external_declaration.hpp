#ifndef ast_external_declaration
#define ast_external_declaration

#include "_ast_abs.hpp"
#include <regex>

/*
external_declaration
0	: function_definition
1	| declaration
;
*/

class external_declaration: public ast_abs{
  int type;
  astPtr data;

public:
  external_declaration(int t, astPtr d):type(t),data(d){}

  ~external_declaration() override{
    delete data;
  }

  void py(std::string& dst) const override{
    switch (type) {
      case 0:
        data->py(dst);
        get_global_variable(dst);
      case 1:
      data->py(dst);
    }
  }

  void mp() const override{
    switch (type){


      default:
      notImplemented();
    }
  }

};

#endif
