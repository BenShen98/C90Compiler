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
#include "ast/algebra_enum.hpp"

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

    /*
     * TODO: non-float must in genReg, float may be in genReg & floatReg
     * CHECK genReg when handling float
     */

    // temporary reg for non floating point
    std::vector<Reg> tGeneralReg;
    std::string tGenRegName(int regIdx);
//    std::string tGenRegName(const RegItr& itr);

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

    //ptr will be invalide if element is inserted to the vector
    EntryPtr getInfo(int id) const;


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
    RegItr loadGenReg(int id, bool load=true);
    RegItr findFreeGenReg( );

/*
 * MIPS function
 */
    void _li(std::string reg,std::string imm, std::string comment=""){
        buffer.push_back("li "+ reg + ',' + imm + " #" + comment + '\n');
    }

    void _add(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("add " + d + ',' + s + ',' + t +" #" + comment + '\n');
    }

    void _addi(std::string t,std::string s,std::string imm, std::string comment=""){
        buffer.push_back("addi " + t + ',' + s + ',' + imm +" #" + comment + '\n');
    }

    void _addiu(std::string t,std::string s,std::string imm, std::string comment=""){
        buffer.push_back("addiu " + t + ',' + s + ',' + imm +" #" + comment + '\n');
    }

    void _addu(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("addu " + d + ',' + s + ',' + t +" #" + comment + '\n');
    }

    void _and(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("and " + d + ',' + s + ',' + t +" #" + comment + '\n');
    }

    void _andi(std::string t,std::string s,std::string imm, std::string comment=""){
        buffer.push_back("andi " + t + ',' + s + ',' + imm +" #" + comment + '\n');
    }

    /* ... */

    /*
     * C instruction
     */
    void algebra(enum_algebra algebra, int result,Type resultType, int op1, int op2, bool free1, bool free2, std::string comment);


public:

/*
 * constructor & destructor for frame, clear register
 */

    void newFrame(std::string name);
    void endFrame(); //call flush

    void dump();



/*
 * insertion of new variable/argument
 */

    // type CANNOT be modified once push_back
    /*
     *  reserved data can only be used as result filed for assignment
     *  immediate is the replacement of original push_back
     */
    int reserveId(int size, Type type, std::string identifier="" );
    int immediate(int size, std::string data, Type type, std::string identifier="" );

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

    //read/write reg (auto LOAD and SPILL from/to stack)
    // difference : write will set dirty flag
    /*
     * IF CODE requires both read and write:
     * Call readGenReg THEN writeGenReg, otherwise
     */
//    std::string readGenReg(int id);
//    std::string writeGenReg(int id);

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
 * C instruction
 */

//    //TODO::  {MUL,DIV,MOD ,ADD,SUB, LEFT_,RIGHT_, SMALLER,GREATER, LE_,GE_,EQ_,NE_, AND,XOR,OR, AND_,OR_, };

    void add(int result, Type resultType, int op1, int op2, bool free1=false, bool free2=false, std::string comment="");




//
//        // TODO: type promotion
//        type=TYPE_SINGED_INT;
//
//        switch (type&0x3){
//            case TYPE_UNSIGNED_INT:
//
//            case TYPE_SINGED_INT:
//
//                break;
//        }
//    }

};


#endif //C90_MP_HPP
