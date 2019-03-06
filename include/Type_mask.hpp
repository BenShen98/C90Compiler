//
// Created by ben on 2019/3/6.
//

#ifndef C90_MP_MASK_HPP
#define C90_MP_MASK_HPP


/*
# Least two significant bit
| BIT 1 | BIT 0 | MEANING      |
|-------|-------|--------------|
| 0     | 0     | SINGLE FLOAT |
| 0     | 1     | DOUBLE FLOAT |
| 1     | 0     |  SIGNED INT |
| 1     | 1     | UNSIGNED INT   |

 BIT
 3      ARRAY FLAG

 31     IS DIRTY (only used by reg)
 *
 */

// type register
typedef enum _type{
    //type code
    TYPE_SINGLE_FLOAT=0x0,
    TYPE_DOUBLE_FLOAT=0x1,
    TYPE_SINGED_INT=0x2,
    TYPE_UNSIGNED_INT=0x3,


    //type mask
    //use by mask & {type}, only return true when {type} confirms to mask
    MASK_IS_FLOAT=0x2;
    MASK_IS_ARRAY=0x4;
    MASK_IS_DIRTY=0x8000000;


} Type;


#endif //C90_MP_MASK_HPP
