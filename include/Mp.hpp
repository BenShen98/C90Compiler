//
// Created by ben on 2019/3/6.
//

#ifndef C90_MP_HPP
#define C90_MP_HPP

#define T_GENERAL_REG_SIZE 8
#define T_FLOAT_REG_SIZE 12


#include <string>
#include <map>
#include <vector>
#include <iostream>


#include "Mp_Type.hpp"

class Mp {

private:

    //funcName of current function
    std::string funcName;

    /*
 * internal struct
 */


//    //function prototype
//    typedef struct _prototype : Entry{
//        int size;
//        std::vector<Entry>;//first is return type, after is argument
//        std::string name;
//    } Prototype;

    //argument passing





/*
 * Buffers for output assembly
 */
    int stack_size;

    std::vector<std::string> buffer;
    std::vector<int> postEditPtr; //line need to replace index _[0-9]_ to top_id-$$

    //write current buffer to ffout
    std::string calOffset(const std::string& str);


/*
 * temporary register mapping
 */
    int freshCounter;

    // temporary reg for non floating point
    std::vector<Reg> tGeneralReg;
    std::string tGenRegName(int regIdx);

//    //temporary reg for floating point
//    std::vector<Reg> tFloatReg = std::vector<Reg>(T_FLOAT_REG_SIZE,{0,-1});

/*
 * Stack
 */
    int top_id;

    std::vector<Entry> entries;

    void sw_sp(std::string reg,int id, std::string comment=""){
        postEditPtr.push_back(buffer.size());//push_back idx of next line
        buffer.push_back("sw " + reg + ",_" + std::to_string(id) + "_($sp) #" + comment + '\n');
    }

    void lw_sp(std::string reg,int id, std::string comment=""){
        postEditPtr.push_back(buffer.size());//push_back idx of next line
        buffer.push_back("lw " + reg + ",_" + std::to_string(id) + "_($sp) #" + comment + '\n');
    }


/*
 * make function call
 */
    int arg_top_id;

    // mapping which stores all the functions
    //need further check the best data struct for this
//    std::map<const std::string name, std::vector<Entry>> functions;

//    std::vector<Arg> args;

    //iterator for function
    //idx 0 for return variable, later one args
    std::vector<Entry>::iterator paraItr;

// TODO START WITH FUNCTION WITHOUT ARGUMENT

/*
 * get param of current function call
 */


/*
 * Internal General Functions
 */

    //  return REG INDEX if already in register
    // load id from stack to general register, return REG INDEX
    // spill least fresh register to stack if necessary
    int loadGenReg(int id);
    int findFreeGenReg();


public:

/*
 * constructor & destructor for frame, clear register
 */

    void newFrame(std::string name);
    void endFrame(); //call flush

    void dump(std::ostream& s);



/*
 * insertion of new variable/argument
 */

    // reserve space in `local` part of STACK, put data register (DOES not write data to stack)
    // type CANNOT be modified once push_back
    int push_back(int size,std::string data, Type type, std::string identifier="" );
//    int push_back(enum_algebra op, int rhs, int lhs, std::string identifier="" );

//    int push_back_array();


/*
 * make function call
 */

    //init paraItr, itr first element (ignore if is not struct)
    void initFunc(std::string name);

//    //take CONTENT in id as agreement, COPY the whole size in stack
//    //(use for int; single/double float; ptr; struct) NOT FOR ARRAY e.g. void foo(int* x)
//    void addArg(int id);
//
//    //USE THIS for copy the whole array i.e. void foo(int[] x) ,
//    void addArg_cpArray(int id);
//
//    //take the imm as data
//    //derive its size and type from function declaration
//    void addArg_Imm(std::string data);//const argument

    //check if all argument had been filled, and issue jal instruction
    //write back all register
    void commitFunc();

    

/*
 * data modification
 */

    //find id (offset used for array ONLY)
    int getId(std::string identifier, int offset=0);

    // get info about the id
    EntryPtr getInfo(int id) const;

    //read/write reg (auto LOAD and SPILL from/to stack)
    // difference : write will set dirty flag
    std::string readGenReg(int id);
    std::string writeGenReg(int id);

    //discard reg without saving its value
    bool discardGenReg(int id);

//    no longer needed
    void writeBackAll();//before function call, save all t register
//    void writeBack(int regIdx);

    //given a id, copy its data, and return the copies id
    int copyStack(int id);


/*
 * pointer and deference
 */
//int getReference(int id);
//int derReference(int id);

/*
 * size of
 */
    int sizeOf(Type type);
//    std::string sizeOf() // for expression

/*
 * MIPS instruction
 */
    void li(std::string reg,std::string imm, std::string comment=""){
        buffer.push_back("li " + reg + ',' + imm + " #" + comment + '\n');
    }

};


#endif //C90_MP_HPP
