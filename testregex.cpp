// // Example program
// #include <iostream>
// #include <string>
// #include <regex>
//
// std::string get_global_variable(std::string str);
//
// int main()
// {
//  std::string temp = get_global_variable("x=9");
//  std::cout<<"OUTPUT"<<temp<<std::endl;
//  return 0;
// }
//
// std::string get_global_variable(std::string str){
// std::regex word (".*(().*())");
// std::string equal("=");
// std::size_t foundequal = str.find(equal);
// std::cout<<foundequal;
// if (!std::regex_match(str,word)){
//   if (foundequal!=std::string::npos){
//     std::cout<<std::endl;
//     return str.substr(0,foundequal);
//   }
//   else{
//     return str;
//   }
// }
//   else{
//     return "";
//   }
// }



// Example program
#include <iostream>
#include <string>
#include <regex>


 inline void get_global_variable(std::string& str){
    std::regex func_def (".*[(].*[)].*");
    if (std::regex_match(str,func_def)){
        // when is function defination
     std::cout << "get func " << str<<"\n";
    str= "";

    }else{
        // when is NOT function defination
        int equal_idx=str.find("=");
        if(equal_idx!=std::string::npos){
            str.erase(equal_idx,str.size());
        }
         std::cout << "global var pushback, " << str<<"\n";
        // globalvar.push_back(str);

    }
  }


int main()
{
    std::string tst="foo()=0";
    get_global_variable(tst);
    std::cout << tst<<"\n";

    tst="x";
    get_global_variable(tst);
    std::cout<< tst<<"\n";

}
