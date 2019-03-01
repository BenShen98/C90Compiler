//
// Created by ben on 2019/2/27.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <vector>
#include <string>

#define STACK_INIT_SIZE 512

#define STACK_INT_MASK 0x1
#define STACK_DOUBLE_MASK 0x2
#define STACK_REG_MASK 0x4
#define STACK_ARG_MASK 0x8
#define STACK_EMPTY_MASK 0x10
#define STACK_RETURNADDRESS_MASK 0x20
#define STACK_TYPE_MASK 0x80000000

/*
 * This class is used to abstract the index calculation and other interaction with the stack memory in MIPS
 * When use the class below, the index of vector is used as ID
 * When push items to stack, the id is returned
 *
 * In MIPS the stack is full descending,
 * When the constructor of the class is called, we assume register SP is at the highest empty address possible
 * where relative_sp=0
 * the increment of ID correspond to the decrement of SP
 *
 * USE BYTE as unit for size i.e. 1 word have size 4
 *
 * MEANING OF TYPE FILED
 * each bit of type is used to store the different type info, let 0 be LSB, 31 be MSB
 * BIT  |       =1        |          =0          |
 *  0   |   interger      |  float/double        |
 *  1   |   double        |       float          |
 *  2   |   is_reg        |  not_reg            |
 *  3   |   is_arg        |  not_arg            |
 *  4   |   is_empty      | not_empty
 *  5   |   is_RA      | not_RA
 *  31  |   is_type_filed | EXCEPTION
 *
 */

class Stack {

private:

//data struct
    typedef struct _entry{
        int size; //in term of byte
        int type;
        std::string name;
    } entry;

    //use byte address
    typedef struct _frame{
        int start_id;
        int start_offset;
    } frame;

//  meta_data
    int relative_sp=0;
    std::vector<int> frame_id; // point to the start of a frame
    bool need_flush= false; // set to true, if data entry does not match meta_data, write assembly to file

// data
    std::vector<entry> entries;


public:
    Stack();

    void flush();
    bool checkSafeEntryInsert(int newEntryType) const;
    void debugFrame();

    //(INPUT)stack insertion
    void insertFrame();
    void deleteFrame();
    int push_back(int size, int type, std::string name ); // return id of insertion

    //(OUTPUT) flush() have be called before return data (given need_flush=true)
    // get address of data in form of `24($sp)`
    std::string find(int id); // from id (index of array)
    std::string find(std::string name); // search by variable name, return first found from back of array(variable shadowing)

    inline bool isInt(int id){
        return (entries[id].type & STACK_INT_MASK);
    }

    inline bool isDouble(int id){
        return (entries[id].type & STACK_DOUBLE_MASK);
    }

    inline bool isReg(int id){
        return (entries[id].type & STACK_REG_MASK);
    }

    inline bool isArg(int id){
        return (entries[id].type & STACK_ARG_MASK);
    }

    inline bool isEmpty(int id){
        return (entries[id].type & STACK_EMPTY_MASK);
    }

    inline bool isRA(int id){
        return (entries[id].type & STACK_RETURNADDRESS_MASK);
    }

};

#endif //C90_CONTEXT_HPP
