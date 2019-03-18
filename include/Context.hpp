//
// Created by Ben Shen on 2019-03-15.
//

#ifndef C90_CONTEXT_H
#define C90_CONTEXT_H

#include <vector>
#include <string>

#include "Context_Type.hpp"


class Context {

private:

    /*
     * Context DATA
     */
    Functions functions;

    /*
     * Temporary storage of function method
     */

    //for decelerate CURRENT function
    std::string _funcName;
    Paras _funcParas;

//    //for query OTHER function (MIPS?)
//    Functions::cons_iterator




public:

    /*
     *  FUNCTION METHOD
     */

    //function declaration/ definition
    void addFunc(std::string name, Type returnType); //return false if function already exist
    void addFuncPara(Type paraType, std::string paraName);
    void commitFunc();

    Functions::const_iterator getFunc(std::string name);

//    // MIPS ???
//    // function get CURRENT para (negative stack id)
//    Type getReturnType();
//
//
//    // set OTHER function's para (arg area in stack)
//    void callFunc(std::string funcName);
//    void setCallArg(int id);
//    void commitCall();




    /*
     *   GLOBAL VARIABLE
     */



    /*
     *   PTR and ARRAY
     */




};


#endif //C90_CONTEXT_H
