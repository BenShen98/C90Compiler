//
// Created by ben on 2019/2/27.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <vector>
#include <string>
#include <stdexcept>


//#include "Mp.hpp"

#define STACK_INIT_SIZE 512

#define STACK_INT_MASK 0x1
#define STACK_DOUBLE_MASK 0x2
#define STACK_REG_MASK 0x4
#define STACK_ARG_MASK 0x8
#define STACK_EMPTY_MASK 0x10
#define STACK_RETURNADDRESS_MASK 0x20
#define STACK_ARRAY_MASK 0x40
#define STACK_TYPE_MASK 0x80000000

/*
 * BUG: CURRENTLY IS ONLY SINGLE WORLD ALIGNED
 *      WILL NOT WORK FOR DOUBLE
 *
 * This class is used to abstract the index calculation and other interaction with the stack memory in MIPS
 * When use the class below, the distance from initial $sp is used as ID
 * When push items to stack, the id is returned
 *
 * In MIPS the stack is full descending,
 * When the constructor of the class is called, we assume register SP is at the highest empty address possible
 * where let the $SP be 'SP, the variable SP = -($SP - 'SP) (when stack is flushed)
 * the increment of ID correspond to the decrement of SP
 *
 * USE BYTE as unit for size i.e. 1 word have size 4
 *
 * flush is ONLY needed before output to ffout
 */

class Stack {
friend class Mp;

private:

//data struct
    typedef struct _entry{
        int size; //in term of byte
        int top_id;
        int type;
        std::string name;
    } entry;

    //use byte address
    typedef struct _frame{
        int top_id;
        int size;// size = distance from the top_id to end of current frame
    } Frame;

//  meta_data
    int sp=0; // define $sp as 0 at start of program execution,decrease as stack grow
    std::vector<Frame> frames;
    bool need_flush= false; // set to true, if data entry does not match meta_data, write assembly to file

// data
    std::vector<entry> entries;


public:
    Stack();

    void flush();

    //(INPUT)stack insertion
    void insertFrame();
    int deleteFrame(); //return the new top_id after delete frame, (used to free register)
    int push_back(int size, int type, std::string name ); // return stack id of insertion

    //(OUTPUT) flush() have be called before return data (given need_flush=true)
    // get address of data in form of `24($sp)`
    std::string getById(int id); // from id (index of array)
    std::string getByName(std::string name, int offsetByte=0); // search by variable name, return first found from back of array(variable shadowing)
    int findId(std::string name, int offsetByte=0);

    //alignment issue
    bool checkSafeEntryInsert(int newEntryType) const;

    //debug tools
    void debugFrame();

//    inline bool isInt(int id){
//        return (entries[id].type & STACK_INT_MASK);
//    }
//
//    inline bool isDouble(int id){
//        return (entries[id].type & STACK_DOUBLE_MASK);
//    }
//
//    inline bool isReg(int id){
//        return (entries[id].type & STACK_REG_MASK);
//    }
//
//    inline bool isArg(int id){
//        return (entries[id].type & STACK_ARG_MASK);
//    }
//
//    inline bool isEmpty(int id){
//        return (entries[id].type & STACK_EMPTY_MASK);
//    }
//
//    inline bool isRA(int id){
//        return (entries[id].type & STACK_RETURNADDRESS_MASK);
//    }

};

#endif //C90_CONTEXT_HPP
