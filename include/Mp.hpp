//
// Created by ben on 2019/3/6.
//

#ifndef C90_MP_HPP
#define C90_MP_HPP

#define T_GENERAL_REG_SIZE 8
#define T_FLOAT_REG_SIZE 12


#include <string>
#include <vector>

#include "Type_mask.hpp"

class Mp {

private:

    //funcName of current function
    std::string funcName;

    /*
 * internal struct
 */
    typedef struct _reg{
        Type type;
        int id; //negative id means it is free register
        unsigned int freshness; // the higher the value, the more resent it had been used
    } Reg;

    typedef struct _entry{
        int size; //in term of byte
        int top_id;
        Type type;
        std::string name;
    } Entry;

    typedef const Entry * const EntryPtr;

    //function prototype
    typedef struct _prototype{
        int size;
        std::vector<Entry>;//first is return type, after is argument
        std::string name;
    } Prototype;

    //argument passing
    typedef enum _argType{
        BY_ID,
        BY_IMM,
        BY_CP_ARRAY
    } ArgType;

    typedef struct _arg{
        ArgType type;
        int id, //for arg by id AND arg by copy array
        std::string imm, //for arg by imm

    } Arg;




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

    void sw_sp_local(std::string reg,int id, std::string comment=""){
        postEditPtr.push_back(buffer.size());//push_back idx of next line
        buffer.push_back("sw " + reg + ',_' + std::to_string(id) + "_ #" + comment + '\n');
    }

    void lw_sp_local(std::string reg,int id, std::string comment=""){
        postEditPtr.push_back(buffer.size());//push_back idx of next line
        buffer.push_back("lw " + reg + ',_' + std::to_string(id) + "_ #" + comment + '\n');
    }

    void sw_sp_local(std::string reg,int id, std::string comment=""){
        postEditPtr.push_back(buffer.size());//push_back idx of next line
        buffer.push_back("sw " + reg + ',¬' + std::to_string(id) + "¬ #" + comment + '\n');
    }


/*
 * function call
 */

// TODO START WITH FUNCTION WITHOUT ARGUMENT

    std::vector<Arg> args;
    int arg_top_id;

    void


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
    std::map<const std::string name, std::vector<Entry>> functions;

    void newFrame(std::string name);
    void endFrame(); //call flush



/*
 * insertion of new variable/argument
 */

    // reserve space in `local` part of STACK, put data register (DOES not write data to stack)
    // type CANNOT be modified once push_back
    int push_back(int size,std::string data, Type type, std::string identifier="" );
//    int push_back_array();


/*
 * function call
 */



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

    void commit

    

/*
 * data modification
 */

    //find id (offset used for array ONLY)
    int getId(std::string identifier, int offset=0);

    // get info about the id
    EntryPtr getInfo(id);

    //read/write reg (auto LOAD and SPILL from/to stack)
    // difference : write will set dirty flag
    std::string readGenReg(int id);
    std::string writeGenReg(int id);

    //discard reg without saving its value
    bool discardGenReg(int id);

//    no longer needed
//    void writeBackAll();//before function call, save all t register
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
//    std::string sizeOf(Type type);
//    std::string sizeOf() // for expression

/*
 * MIPS instruction
 */
    void li(std::string reg,std::string imm, std::string comment=""){
        buffer.push_back("li " + reg + ',' + imm + " #" + comment + '\n');
    }

};


#endif //C90_MP_HPP
