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

  void py(std::string& dst)const override{
    switch (type) {
      case 0:
      data->py(dst);
      for (int i = 0; i<globalvar.size();i++){
        dst += "global " + globalvar[i] + '\n';
      }
      case 1:
      data->py(dst);
      dst = get_global_variable(dst);
  }
}

  void mp() const override{
    switch (type){


      default:
      notImplemented();
    }
  }

  inline std::string get_global_variable(std::string str){
    std::regex word (".*(().*())");
    std::string equal("=");
    std::size_t foundequal = str.find(equal);
    if (!std::regex_match(str,word)){
      if (foundequal!=std::string::npos){
        globalvar.push_back(str);
        return str.substr(0,foundequal);
      }
    }
    else{
      return "";
    }
  }


};

#endif
