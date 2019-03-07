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
      get_global_variable(dst);
  }
}


    std::string c()const override{
      return data->c();
    }

    void mp() const override{
        switch (type){


            default:
                notImplemented();
        }
    }
private:
     inline void get_global_variable(std::string& str)const{
     std::regex func_def (".*[(].*[)].*");
     if (std::regex_match(str,func_def)){
         // when is function defination
         //std::cout << "get func " << str<<"\n";
     str= "";

     }else{
         // when is NOT function defination
         int equal_idx=str.find("=");
         if(equal_idx!=std::string::npos){
             str.erase(equal_idx,str.size());
         }
        //std::cout << "global var pushback, " << str<<"\n";
        globalvar.push_back(str);
     }
   }

};

#endif
