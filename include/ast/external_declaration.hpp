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
      //std::cerr<<"WARNING THIS IS PRINTING"<<dst<<std::endl;
      break;
      case 1:
      data->py(dst);
      //std::cerr<<"WARNING THIS IS PRINTING declaration "<<dst<<std::endl;
      get_global_variable(dst);
      //std::cout<<globalvar.size();
      break;
  }
}

  void mp() const override{
      data->mp();
  }

  inline void get_global_variable(std::string& str)const{
     std::vector<std::string> fields;
     std::regex func_def (".*[(].*[)].*");
     if (std::regex_match(str,func_def)){
         // when is function defination
         //std::cout << "get func " << str<<"\n";
     str= "";

     }else{
         //boost::split(fields,str,boost::is_any_of("\n"));
         std::string token;
         std::istringstream tokenstream(str);
         while(std::getline(tokenstream,token,'\n')){
           fields.push_back(token);
         }
         // when is NOT function defination
         //str.erase(equal_idx,str.size());
         for (int i=0;i<fields.size();i++){
           int equal_idx=fields[i].find("=");
           std::string tempstr(fields[i],0,equal_idx);
           //std::cout << "global var pushback, " << tempstr<<"\n";
           globalvar.push_back(tempstr);
//           std::cout<<fields[i]<<std::endl;
         }
     }
   }

};

#endif
