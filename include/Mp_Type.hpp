//
// Created by ben on 2019/3/6.
//

#ifndef C90_MP_TYPE_HPP
#define C90_MP_TYPE_HPP

#include <vector>


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

// address type
typedef std::vector<int> AddressType;

typedef enum _type{
    /*
     * basic data type
     */
    CHECK_TYPE_BASIC=0x7,
    CHECK_TYPE_BASIC_N=~CHECK_TYPE_BASIC,

    TYPE_SIGNED_INT=    0x0,
    TYPE_UNSIGNED_INT=  0x1,
    TYPE_SINGLE_FLOAT=  0x2,
    TYPE_DOUBLE_FLOAT=  0x3,

    TYPE_VOID=0x4,

    MASK_IS_FLOAT=  0x2,
    MASK_IS_VOID=TYPE_VOID,

    //advanced type
    FLAG_IS_ADDRESS=  0x8,
    CHECK_ADDR_FLAG_N=~FLAG_IS_ADDRESS,

    TYPE_SIGNED_INT_PTR=    FLAG_IS_ADDRESS | TYPE_SIGNED_INT,
    TYPE_UNSIGNED_INT_PTR=  FLAG_IS_ADDRESS | TYPE_UNSIGNED_INT,
    TYPE_SINGLE_FLOAT_PTR=  FLAG_IS_ADDRESS | TYPE_SINGLE_FLOAT,
    TYPE_DOUBLE_FLOAT_PTR=  FLAG_IS_ADDRESS | TYPE_DOUBLE_FLOAT,

    /*
     * for register only (only [31:30] bit matter)
     */
    CHECK_REG=0xC0000000,
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

// ==
inline bool isEqual(Type a,Type b){
    return (static_cast<int>(a) == static_cast<int>(b));
}

inline bool isBasicTypeEqual(Type a,Type b){
    return (static_cast<int>(a&CHECK_TYPE_BASIC) == static_cast<int>(b&CHECK_TYPE_BASIC));
}
//inline bool operator==(const Type& a,const Type& b)
//{return (static_cast<int>(a) == static_cast<int>(b));}

//inline bool operator!=(const Type& a,const Type& b)
//{return !(a==b);}

/*
 * basic data type (int, float)
 */

//check
inline bool isDoubleFloat(Type t){
    return isEqual( (t&CHECK_TYPE_BASIC) , TYPE_DOUBLE_FLOAT );
}

inline bool isVoid(Type t){
    return t&MASK_IS_VOID;
}

inline bool isSingleFloat(Type t){
    return isEqual( (t&CHECK_TYPE_BASIC) , TYPE_SINGLE_FLOAT );
}

inline bool isFloat(Type t){
    return t&MASK_IS_FLOAT;
}

inline bool isSignedInt(Type t){
    return isEqual( (t&CHECK_TYPE_BASIC) , TYPE_SIGNED_INT );
}

inline bool isUnsignedInt(Type t){
    return isEqual( (t&CHECK_TYPE_BASIC) , TYPE_UNSIGNED_INT );
}

inline bool isInt(Type t){
    //only have int and float at the moment
    return !isFloat(t);
}

//set
inline void setVoid(Type &t){
    t=(t&CHECK_TYPE_BASIC_N)|TYPE_VOID;
}

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
    return isEqual( (t&CHECK_REG) , REG_DIRTY );
}

inline bool isRegEmpty(Type t){
    return isEqual( (t&CHECK_REG) , REG_EMPTY );
}

inline bool isRegUnkown(Type t){
    return isEqual( (t&CHECK_REG) , REG_UNKNOWN );
}

inline bool isRegSync(Type t){
    return isEqual( (t&CHECK_REG) , REG_SYNC );
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
 * advanced data flag
 */

inline bool isAddressFlagSet(Type t){
    return t&FLAG_IS_ADDRESS;
}

inline void setAddressFlag(Type& t){
    t= t|FLAG_IS_ADDRESS;
}

inline void resetAddressFlag(Type& t){
    t= t & CHECK_ADDR_FLAG_N;
}


/*
 *  sizeOf
 */

//asking for type its self
inline int sizeOf(Type type) {
//    if( isDoubleFloat(type) ){
//        //only double is 8 byte
//        return 8;
//    }else if(isVoid(type)){
//        return 0;
//    }else{
//        //all other is 4 byte wide (ptr, int, float, etc
//        return 4;
//    }

    return 4;
}


//asking for the underlying type

//      when getInner==True => call on X[2][3] give Size of X[2]
inline int sizeOf(Type t, const AddressType& v, bool getInner = false) {
    AddressType::const_reverse_iterator ritr = v.rbegin();
    //does not work for double
    //need check if is a pointer of pointer
    int size=4;

    if(getInner)
        ++ritr;

    //todo: for inner, need check v.size()>2

    if(isAddressFlagSet(t) && !v.empty() && ritr!=v.rend()){ //check is address, check v is not empty, check itr is not pastend
        for( ; ritr!=v.rend() ; ++ritr){
            if(*ritr<0)
                break;

            size *= *ritr;
        }
    }

    return size;
}



//return true if is still address, return false if is fully deference
inline void deference(Type& t, AddressType& v) {

    if(v.size()<=1){
        resetAddressFlag(t);
    }

    if(!v.empty()){
        v.pop_back();
    }

}

inline void getReference(Type& t, AddressType& v) {
    // & operator
    setAddressFlag(t);
    v.push_back(-1);

}


inline int squareBraket(Type& t, AddressType& v){
    // [ ] operator
    deference(t, v);
    return sizeOf(t, v);
};

inline std::ostream& operator << (std::ostream& os, const AddressType v)
{
    AddressType::const_iterator i = v.begin();
    os<<'{';
    if(!v.empty()){
        for ( ; i != v.end(); ++i)
        {
            os <<*i<<", ";
        }
    }
    os<<'}';
    return os;
}



/*
 * struct
 */

typedef struct _stackid{
    int level;
    int top_id;

    std::string str()const {
        return std::to_string(top_id);
//        return std::to_string(level)+":"+id.str();

    }

} StackId;

inline bool operator==(const StackId& lhs, const StackId& rhs)
{
    return lhs.level==rhs.level && lhs.top_id==rhs.top_id;
}

typedef struct _reg{
    Type type=REG_EMPTY;
    StackId id; //negative id means it is free register
    int freshness; // the higher the value, the more resent it had been used
} Reg;

typedef Reg* RegPtr;


typedef struct _entry{
    int size; //in term of byte
    int top_id;
    Type type;
    std::string name;
    AddressType addr;
} Entry;

typedef const Entry * EntryPtr;

typedef struct _scope{
    std::vector<Entry> entries;
    //typedef
    //enum

} Scope;

typedef std::vector<Scope> Scopes;



typedef struct _result{

//        union{
//            StackId id;     // used for operation which have dst register
//            Type type; //used for declaration_specifiers
//        };

    StackId id;     // used for operation which have dst register
    int num;        // used by constant expression
    Type type=TYPE_SIGNED_INT; //used for declaration_specifiers

    std::string str;// this field need refactor

    bool freeable=false;

    AddressType addr;

} Result;


//typedef struct _msg {
//    StackId id;
//    int reg;
//    Type type;
//} Msg;

inline std::ostream& operator << (std::ostream& os, const StackId& s)
{
    os<<s.str();
    return os;
}


#endif //C90_MP_MASK_HPP
