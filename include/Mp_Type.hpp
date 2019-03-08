//
// Created by ben on 2019/3/6.
//

#ifndef C90_MP_TYPE_HPP
#define C90_MP_TYPE_HPP



/*
# Least two significant bit
| BIT 1 | BIT 0 | MEANING      |
|-------|-------|--------------|
| 0     | 0     |  SIGNED INT |
| 0   | 1     | UNSIGNED INT   |
 | 1     | 0     | SINGLE FLOAT |
| 1     | 1     | DOUBLE FLOAT |

 BIT
 3      ARRAY FLAG

 31     IS DIRTY (only used by reg, reserved)
 *
 */

// type register
typedef enum _type{
    //type code

    TYPE_SINGED_INT=    0x0,
    TYPE_UNSIGNED_INT=  0x1,
    TYPE_SINGLE_FLOAT=  0x2,
    TYPE_DOUBLE_FLOAT=  0x3,

    //type mask
    //use by mask & {type}, only return true when {type} confirms to mask
    MASK_IS_FLOAT=  0x2,
    MASK_IS_ARRAY=  0x4,
    MASK_IS_DIRTY=  0x80000000,
    MASK_IS_FREE=   0x40000000


} Type;

//overload bitwise or
inline Type& operator|=(Type& a,const Type& b)
{return a=static_cast<Type>(static_cast<int>(a) | static_cast<int>(b));}

inline Type& operator|(Type a, const Type& b)
{return a|=b;}

//overload bitwise and

inline Type& operator&=(Type& a,const Type& b)
{return a=static_cast<Type>(static_cast<int>(a) & static_cast<int>(b));}

inline Type& operator&(Type a, const Type& b)
{return a&=b;}


/*
 * struct
 */
typedef struct _reg{
    Type type;
    int id; //negative id means it is free register
    int freshness; // the higher the value, the more resent it had been used
} Reg;

typedef struct _entry{
    int size; //in term of byte
    int top_id;
    Type type;
    std::string name;
} Entry;

typedef const Entry * const EntryPtr;

typedef struct _result{

//        union{
//            int id;     // used for operation which have dst register
//            Type type; //used for declaration_specifiers
//        };

    int id;     // used for operation which have dst register
    Type type; //used for declaration_specifiers
    std::string str;

    bool freeable=false;
} Result;


#endif //C90_MP_MASK_HPP
