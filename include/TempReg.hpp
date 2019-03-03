//
// Created by ben on 2019/3/2.
//

#ifndef C90_TEMPREG_HPP
#define C90_TEMPREG_HPP

#include <vector>
#include <string>
#include <stdexcept>

#define TREG_SIZE 8

//if REG_DIRTY_MASK==1 means the current register need write back
#define REG_DIRTY_MASK STACK_TYPE_MASK

/*
 * ALL operation SHOULD NOT be done directly on register
 *
 * Currently implementation uses Spilling
 * Which is the easiest to implement, (performance have lower priority in this assignment)
 *
 * DATA in register must be referred by the stack id
 * 1) Even for temporary data (without variable name in C),
 *      data must be push_back to Stack, and obtain id;
 *      Although as shown in Stack.hpp, this operation may not actually produce instruction
 *      (i.e. When that frame is poped before it got flush, for performance optimisation)
 *
 *
 * 2) When create temporary data, (done by call makeTemp)
 *      1. Call push_back function on stack, receive stack ID as token
 *      2. Call initReg to init data, the dirty bit NEED to set to TRUE
 */

extern std::ofstream ffout;

class TempReg {

private:

    typedef struct _reg{
        int type;
        int id; //negative id means it is free register
    } Reg;

    std::vector<Reg> tReg = std::vector<Reg>(TREG_SIZE,{0,-1});

    //get register name from regIdx
    std::string MPname(int regIdx);

    //returns regIdx, NOT stack ID, for INTERNAL ONLY
    int findFreeReg();

    //returns regIdx, which contain data for id
    int find(int id);

    // manually free an register, NO WRITE BACK will be doen even if the reg is dirty
    bool freeReg(int id);

    //called when stack FRAME get deallocated
    void freeRegHigherThan(int id);



public:


//     init data for UNINITIALIZED stack ID, set dirty bit to 0 (TRUE)
//    std::string initReg(int id, int initdata, int type);


};


#endif //C90_TEMPREG_HPP
