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

/*
 * Buffers for output assembly
 */
    std::vector<std::string> buffer;
    std::vector<int> postEditPtr; //line need to replace index _[0-9]_ to top_id-$$

    //write current buffer to ffout
    void flush();
    std::string calOffset(const std::string& str);


/*
 * temporary register mapping
 */
    int freshCounter=0;

    // temporary reg for non floating point
    std::vector<Reg> tGeneralReg = std::vector<Reg>(T_GENERAL_REG_SIZE,{TYPE_SINGED_INT,-1,0});
    std::string tGenRegName(int regIdx);

//    //temporary reg for floating point
//    std::vector<Reg> tFloatReg = std::vector<Reg>(T_FLOAT_REG_SIZE,{0,-1});

/*
 * Stack
 */
    int top_id;

    std::vector<Entry> entries = std::vector<Entry>(1,{0,0,TYPE_SINGED_INT,""});

    void sw_sp(std::string reg,int id, std::string comment=""){
        postEditPtr.push_back(buffer.size());//push_back idx of next line
        buffer.push_back("sw " + reg + ',_' + std::to_string(id) + "_ #" + comment + '\n');
    }

    void lw_sp(std::string reg,int id, std::string comment=""){
        postEditPtr.push_back(buffer.size());//push_back idx of next line
        buffer.push_back("lw " + reg + ',_' + std::to_string(id) + "_ #" + comment + '\n');
    }

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
    void insertFrame();
    void deleteFrame(); //call flush



/*
 * insertion of new variable/arguement
 */

    // reserve space in `local` part of STACK, put data register (DOES not write data to stack)
    // type CANNOT be modified once push_back
    int push_back(int size,std::string data, Type type, std::string identifier="" );
//    int push_back_array();

    //append the id to arg list
    void addArg(int id);
    

/*
 * data modification
 */

    //find id (offset used for array ONLY)
    int getId(std::string identifier, int offset=0);

    // get info about the id
    const Entry * const getInfo(id);

    //read/write reg (auto LOAD and SPILL from/to stack)
    // difference : write will set dirty flag
    std::string readGenReg(int id);
    std::string writeGenReg(int id);

    //discard reg without saving its value
    bool discardGenReg(int id);

    void writeBackAll();//before function call, save all t register
    void writeBack(int regIdx);


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
