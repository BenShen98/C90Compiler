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
#include <utility>

#include "Mp_Type.hpp"
#include "Context_Type.hpp"

#include "ast/algebra_enum.hpp"
#include "ast/assignment_operator.hpp"

class Mp {

private:

    //funcName of current function
    std::string asCallee_name;
    Paras asCallee_paras;

    int uniqueCounter;

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
    RegPtr tGeneralReg;
    std::string tGenRegName(int regIdx);

    std::string tRegName(const RegPtr itr);

//    //temporary reg for floating point
//    std::vector<Reg> tFloatReg = std::vector<Reg>(T_FLOAT_REG_SIZE,{0,-1});

/*
 * Stack
 */
    int top_id;

    std::vector<Entry> entries;

    void sw_sp(std::string reg,int id, std::string comment=""){

        postEditPtr.push_back(buffer.size());//push_back idx of next line
        buffer.push_back("sw " + reg + ",_" + std::to_string(id) + "_($sp) #" + comment);

    }

    //used when store arguments
    void sw_sp(std::string reg,std::string offset, std::string comment=""){
        buffer.push_back("sw " + reg + "," + offset + "($sp) #" + comment);

    }

    void lw_sp(std::string reg,int id, std::string comment=""){
        postEditPtr.push_back(buffer.size());//push_back idx of next line
        buffer.push_back("lw " + reg + ",_" + std::to_string(id) + "_($sp) #" + comment);

    }

    //ptr will be invalide if element is inserted to the vector
    EntryPtr getInfo(int id) const;


    /*
 * make function call
 */
    //max arg size of all function call
    int arg_max_size;


    std::string asCaller_name;
    Paras asCaller_args; //only used by per-declared function
    int paraIdx;
    int para_offset;
    bool implicitCall;

// TODO START WITH FUNCTION WITHOUT ARGUMENT





/*
 * Internal General Functions
 */

    //  return REG INDEX if already in register
    // load id from stack to general register, return REG INDEX
    // spill least fresh register to stack if necessary
    RegPtr loadGenReg(int id, bool load=true);
    RegPtr findFreeGenReg( );

    void _algebra(enum_algebra operation, RegPtr dst, RegPtr op1, RegPtr op2, std::string comment);

/*
 * MIPS function
 */
    void _li(std::string reg,std::string imm, std::string comment=""){
        buffer.push_back("li "+ reg + ',' + imm + " #" + comment );
    }

    void _add(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("add " + d + ',' + s + ',' + t +" #" + comment );
    }

    void _addi(std::string t,std::string s,std::string imm, std::string comment=""){
        buffer.push_back("addi " + t + ',' + s + ',' + imm +" #" + comment );
    }

    void _addiu(std::string t,std::string s,std::string imm, std::string comment=""){
        buffer.push_back("addiu " + t + ',' + s + ',' + imm +" #" + comment );
    }

    void _addu(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("addu " + d + ',' + s + ',' + t +" #" + comment );
    }

    void _and(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("and " + d + ',' + s + ',' + t +" #" + comment );
    }

    void _andi(std::string t,std::string s,std::string imm, std::string comment=""){
        buffer.push_back("andi " + t + ',' + s + ',' + imm +" #" + comment );
    }

    void _b(std::string label){
        buffer.push_back("b " + label );
    }

    void _comment(const std::string& comment ){
        buffer.push_back("# " + comment );
    }
    void _mul(std::string d,std::string s,std::string t, std::string comment=""){
      //use $LO
        buffer.push_back("mult " + s + ',' + t +" #" + comment );
        buffer.push_back("mflo " + d + '#' + comment );
    }
    void _div(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("div " + s + ',' + t +" #" + comment );
        buffer.push_back("mflo " + d + '#' + comment );
    }
    void _divu(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("divu " + s + ',' + t +" #" + comment );
        buffer.push_back("mflo " + d + '#' + comment );
    }
    void _mod(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("div " + s + ',' + t +" #" + comment );
        buffer.push_back("mfhi " + d + '#' + comment );
    }
    void _modu(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("divu " + s + ',' + t +" #" + comment );
        buffer.push_back("mfhi " + d + '#' + comment );
    }
    void _sub(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("sub " + d + ',' + s + ',' + t +" #" + comment );
    }
    void _subu(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("subu " + d + ',' + s + ',' + t +" #" + comment );
    }
    void _sll(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("sll" + d + ',' + s + ',' + t +" #" + comment );
    }
    void _srl(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("srl" + d + ',' + s + ',' + t +" #" + comment );
    }
    void _sra(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("sra " + d + ',' + s + ',' + t +" #" + comment );
    }
    void _sltu(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("sltu " + d + ',' + s + ',' + t +" #" + comment );
    }
    void _slt(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("slt " + d + ',' + s + ',' + t +" #" + comment );
    }
    void _LE(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("slt " + d + ',' + s + ',' + t +" #" + comment );
        buffer.push_back("xori " + d + ',' + d + ',' + "0x1" +" #" + comment );
    }
    void _LEu(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("sltu " + d + ',' + s + ',' + t +" #" + comment );
        buffer.push_back("xori " + d + ',' + d + ',' + "0x1" +" #" + comment );
    }
    void _EQ(std::string d,std::string s,std::string t, std::string comment=""){
        //might need to andi 0x000ff

        buffer.push_back("xor " + d + ',' + s + ',' + t +" #" + comment );
        buffer.push_back("sltu " + d + ',' + d + ',' + "0x1" +" #" + comment );

    }
    void _NE(std::string d,std::string s,std::string t, std::string comment=""){
      //might need to andi 0x000ff
        buffer.push_back("xor " + d + ',' + s + ',' + t +" #" + comment );
        buffer.push_back("sltu " + d + ',' + "$0" + ',' + d +" #" + comment );

    }
    void _xor(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("xor " + d + ',' + s + ',' + t +" #" + comment );
    }
    void _or(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("or " + d + ',' + s + ',' + t +" #" + comment );
    }
    void _nor(std::string d,std::string s,std::string t, std::string comment=""){
        buffer.push_back("nor " + d + ',' + s + ',' + t +" #" + comment );
    }

    void _jal(std::string label){
        buffer.push_back("jal " + label );
    }


    void _beq(std::string s,std::string t,std::string label){
        buffer.push_back("beq " + s + ',' +t + ',' + label );
    }

    void _bne(std::string s,std::string t,std::string label){
        buffer.push_back("beq " + s + ',' +t + ',' + label );
    }

    void _move(std::string d,std::string s,std::string comment=""){
        buffer.push_back("move " + d + ',' +s +" #"+comment);
    }




    /* ... */

    /*
     * C instruction
     */
    //give op1,op2 (id) returns new op1,op2 (RegPtr) after type promotion,
    //new id may be different
    std::pair<RegPtr, RegPtr> typePromotion(int op1,int op2);

    // if free1=true => convert type in ONE register
    // if free1=false => convert type in ONE register
    // dst1 != op1 at all time, type can not be changed
    // force the duplicated op1 have type of dst
    // the returned regPtr will contain a new id
    RegPtr typeDuplicate(int dst, int op1, bool free1 = false);



public:

/*
 * constructor & destructor for frame, clear register
 */

    void newFrame(std::string name);
    void endFrame(bool logging=true); //call flush

    void dump();//SHOULD be private
    int negation(char type, int op1, bool free1);



/*
 * insertion of new variable/argument
 */

    // type CANNOT be modified once push_back
    /*
     *  reserved data can only be used as RESULT filed for assignment
     *  immediate is the replacement of original push_back
     */
    int reserveId(int size, Type type, std::string identifier="" );
//    void assignImmediate(int id, Type type, std::string data);
    int immediate(int size, std::string data, Type type, std::string identifier="" );

//    int push_back_array();

/*
 * current function call & block control
 */
    void Return();
    void Return(int id);

    int getPara(std::string name);

    // generate and insert label
    std::string mkLabel(const std::string& name);
    void insertLabel(const std::string &label);

    //block control
    void bZero(bool onTrue,  int id, std::string label);

/*
 * make function call
 */

    void callFunc(const std::string& funcName);

//    //take CONTENT in id as agreement, COPY the whole size in stack
//    //(use for int; single/double float; ptr; struct) NOT FOR ARRAY e.g. void foo(int* x)
    void addArg(int id);

//    //take the imm as data
//    //derive its size and type from function declaration
//    void addArg_Imm(std::string data);//const argument

    //check if all argument had been filled, and issue jal instruction
    // provide id with return value
    //write back all register
    int commitCall();
//



/*
 * data modification
 */

    //find id (offset used for array ONLY)
    //todo IF offset is 0, AND is array, DO SOMETHING (return ptr?)
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
//    std::string sizeOf() // for expression

/*
 * C instruction
 */

//    //TODO::  {MUL,DIV,MOD ,ADD,SUB, LEFT_,RIGHT_, SMALLER,GREATER, LE_,GE_,EQ_,NE_, AND,XOR,OR, AND_,OR_, };

    int algebra(enum_algebra algebra,int op1, int op2, bool free1=false, bool free2=false, std::string varName="");

    void assignment(int dst, int op1,enum_assignment operation=ASSIGN, bool free= false);
    // void assignment(int dst, std::string constant);

    //ONLY for INT, used for a++, a--, --a, ++a
    //WHEN prefix=FALSE, a unchanged copy is returned, the original is changed
    int addi(bool perfix, int op1, std::string integer);

    //overwrite regist
//    int makeCopy(int id, bool free1=true); //use assignment instead

    void comment(const std::string& comment ){
        buffer.push_back("# " + comment );
    }

    void branch(std::string label);

    void beq(int id1,int id2,std::string label);

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
