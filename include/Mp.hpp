//
// Created by ben on 2019/3/2.
//

#ifndef C90_MP_HPP
#define C90_MP_HPP


#include <fstream>

#include "Stack.hpp"
#include "TempReg.hpp"

extern std::ofstream ffout;

/*
 * MEANING OF TYPE FILED
 * each bit of type is used to store the different type info, let 0 be LSB, 31 be MSB
 * BIT  |       =1        |          =0          |
 *  0   |   interger      |  float/double        |
 *  1   |   double        |       float          |
 *  2   |   is_reg        |  not_reg            |
 *  3   |   is_arg        |  not_arg            |
 *  4   |   is_empty      | not_empty
 *  5   |   is_RA      | not_RA
 *  31  |   is_type_filed | EXCEPTION (when in stack)
 *  31  |   is_dirty | not_dirty (when in reg)
 *
 */

class Mp {
friend class Stack;
friend class TempReg;

private:
    Stack stack;
    TempReg reg;

    //write data in regIdx back to STACK (normally called when need spill register)
    void writeBack(int regIdx);

    //Load data from stack
    std::string loadFromStack(int id);

public:

    Mp():stack(), reg() {}

    // return $t{regIdx} which contains data with the StackID, if not previously in register, will be loaded to stack
    std::string readReg(int id);
    std::string writeReg(int id);

    //write all dirty register to memory
    void writeBackAll();


    static void add(std::string dst,std::string s, std::string t, std::string comment=""){
            ffout <<" ADD " << dst << ',' << s << ',' << t << " #" << comment << '\n';
    }

    static void addi(std::string dst,std::string s, std::string i, std::string comment=""){
        ffout <<" ADDI " << dst << ',' << s << ',' << i << " #" << comment << '\n';
    }
};


#endif //C90_MP_HPP
