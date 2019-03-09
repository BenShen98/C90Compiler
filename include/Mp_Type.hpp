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

 31,30     reserved by register
 *
 */

// type register
typedef enum _type{
    /*
     * basic data type
     */
    CHECK_TYPE_BASIC=0x3,
    CHECK_TYPE_BASIC_N=~CHECK_TYPE_BASIC,

    TYPE_SIGNED_INT=    0x0,
    TYPE_UNSIGNED_INT=  0x1,
    TYPE_SINGLE_FLOAT=  0x2,
    TYPE_DOUBLE_FLOAT=  0x3,

    MASK_IS_FLOAT=  0x2,

    /*
     * advanced data type
     */
    MASK_IS_ARRAY=  0x4,


    /*
     * for register only (only [31:30] bit matter)
     */
    CHECK_REG=0x3,
    CHECK_REG_N=~CHECK_REG,

    REG_EMPTY=  0x00000000,
    REG_DIRTY=  0x40000000,
    REG_SYNC=   0x80000000,
    REG_UNKNOWN= 0xC0000000,


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
 * basic data type (int, float)
 */

//check
inline bool isDoubleFloat(Type t){
    return (t&CHECK_TYPE_BASIC)==TYPE_DOUBLE_FLOAT;
}

inline bool isSingleFloat(Type t){
    return (t&CHECK_TYPE_BASIC)==TYPE_SINGLE_FLOAT;
}

inline bool isFloat(Type t){
    return t&MASK_IS_FLOAT;
}

//int
inline bool isSignedInt(Type t){
    return (t&CHECK_TYPE_BASIC)==TYPE_SIGNED_INT;
}

inline bool isUnsignedInt(Type t){
    return (t&CHECK_TYPE_BASIC)==TYPE_UNSIGNED_INT;
}

inline bool isInt(Type t){
    //only have int and float at the moment
    return !isFloat(t);
}

//set

inline void setDoubleFloat(Type& t){
    t= (t&CHECK_TYPE_BASIC_N)|TYPE_DOUBLE_FLOAT;
}

inline void setSingleFloat(Type& t){
    t= (t&CHECK_TYPE_BASIC_N)|TYPE_SINGLE_FLOAT;
}

//int
inline void setSignedInt(Type& t){
    t= (t&CHECK_TYPE_BASIC_N)|TYPE_SIGNED_INT;
}

inline void setUnsignedInt(Type& t){
    t= (t&CHECK_TYPE_BASIC_N)|TYPE_UNSIGNED_INT;
}

/*
 * register
 */

//check
inline bool isRegDirty(Type t){
    return (t&CHECK_REG)==REG_DIRTY;
}

inline bool isRegEmpty(Type t){
    return (t&CHECK_REG)==REG_EMPTY;
}

inline bool isRegUnkown(Type t){
    return (t&CHECK_REG)==REG_UNKNOWN;
}

inline bool isRegSync(Type t){
    return (t&CHECK_REG)==REG_SYNC;
}

//set
inline void setRegDirty(Type& t){
    t= (t&CHECK_REG_N)|REG_DIRTY;
}

inline void setRegEmpty(Type& t){
    t= (t&CHECK_REG_N)|REG_EMPTY;
}

inline void setRegUnkown(Type& t){
    t= (t&CHECK_REG_N)|REG_UNKNOWN;
}

inline void setRegSync(Type& t){
    t= (t&CHECK_REG_N)|REG_SYNC;
}

/*
 * advanced data type
 */
inline bool isArray(Type t){
    return t&MASK_IS_ARRAY;
}



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
