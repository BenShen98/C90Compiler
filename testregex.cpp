// Example program
#include <iostream>
#include <string>
#include <regex>

std::string get_global_variable(std::string str);

int main()
{
 std::string temp = get_global_variable("hiuh==das");
 std::cout<<"OUTPUT"<<temp<<std::endl;
 return 0;
}

std::string get_global_variable(std::string str){
std::regex word ("\(");
std::string equal("=");
std::size_t foundequal = str.find(equal);
if (std::regex_search(word,str)){
  if (foundequal!=std::string::npos){
    return str.substr(0,foundequal);
  }
}
  else{
    return "";
  }
}
