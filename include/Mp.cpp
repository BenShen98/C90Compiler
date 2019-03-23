//
// Created by ben on 2019/3/6.
//

#include "Mp.hpp"

#include "Context.hpp"

#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <stdexcept>
#include <regex>
#include <fstream>

#define RETURN_LABEL "EXIT_"+asCallee_name
#define PTR_SZIE 4

extern Context context;
extern std::ofstream ffout;

/*
 * constructor & destructor for frame, clear register
 */

    void Mp::newFrame(std::string name) {
        /*
         * reset all information except the functions's mapping
         */

        //reset buffer
        stack_size=0;
        buffer.clear();
        postEditPtr.clear();

        //reset temporary reg
        freshCounter=0;
        tGeneralReg = new Reg[T_GENERAL_REG_SIZE]; // init
    //    tFloatReg = std::vector<Reg>(T_FLOAT_REG_SIZE,{MASK_IS_FREE,0,0});

        //reset stack
        top_id=0;
        entries.clear();

        //function parameter set up (as callee)
        {
            Functions::const_iterator asCallee;
            if( context.getFunc(name,asCallee) ){ // have side effect
                throw std::runtime_error("func not defined");
            }
            asCallee_name=asCallee->first;
            asCallee_paras=asCallee->second;


            Paras::const_iterator it = asCallee_paras.begin()+1;
            int argOffset=0;

            // todo : pass float & double
            //first element
            for (int i=0; it != asCallee_paras.end() && i<4; ++it, ++i) {
                int eleSize=sizeOf(it->type);
                entries.push_back( {eleSize, argOffset, it->type, it->name } );
                sw_sp("$a"+std::to_string(i), argOffset, "store parameter");

                argOffset-=eleSize;

            }

            // element after forth
            for (; it != asCallee_paras.end() ; ++it) {
                int eleSize=sizeOf(it->type);
                entries.push_back( {eleSize, argOffset, it->type, it->name } );
                argOffset-=eleSize;
            }
            std::reverse(entries.begin(),entries.end());



        }

        //reset function arg set up name (as caller)
        arg_max_size=20;
    //    args.clear();
    //    arg_top_id=0;

    }

    /*
     * flush data
     */
    void Mp::endFrame(bool logging) {

        //calculate zone for `local and temporaries` and `args`
        stack_size = top_id + 4 + arg_max_size; // space for {local},$RA, {opt_place_holder}, {arg_list}

        if(stack_size&0x4){
            stack_size+=4; //make stack frame 8 byte aligned
        }

        //write back dirty register (not needed, for test only)
//        writeBackAll();

/*
 * flush buffer
 */
        // frame setup
        ffout<< ".globl "<<(asCallee_name)<<'\n';
        ffout<<".ent "<<(asCallee_name)<<'\n';
        ffout<< (asCallee_name) <<":\n";
        ffout<< ".frame $fp,"<<stack_size<<",$31\n";
        ffout<<"addiu $sp, $sp, -"<<stack_size<<'\n'; // allocate stack
        ffout<<"sw $31, "<<arg_max_size<<"($sp)"<<'\n';

        //flush content
        std::regex edit("_-?[0-9]*_");
        std::smatch m;
        int editIdx=0;
        unsigned bufIdx=0;


        //iteration while not reached end of postEditPtr
        for( ; editIdx<postEditPtr.size() && bufIdx<buffer.size();++bufIdx){
            if(postEditPtr[editIdx]==bufIdx){
                //change offset
                std::regex_search(buffer[bufIdx], m, edit);
                ffout<<m.prefix()<<calOffset(m[0])<<m.suffix()<<'\n';

                //increment id
                ++editIdx;
            }else{
                ffout<<buffer[bufIdx]<<'\n';
            }
        }

        //iteration when reached end of postEditPtr
        for( ; bufIdx<buffer.size();++bufIdx){
                ffout<<buffer[bufIdx]<<'\n';
        }

        //frame delete
        ffout<<std::string(RETURN_LABEL)<<":\n";
        ffout<<"lw $31, "<<arg_max_size<<"($sp)"<<'\n';
        ffout<<"addiu $sp, $sp, "<<stack_size<<'\n'; // deallocate stack
        ffout<<"j $31\n";
        ffout<<".end "<<(asCallee_name)<<"\n\n";

        //logging and exit
        if(logging)
            dump();

        delete[] tGeneralReg;


    }

    void Mp::dump() {

        std::cerr<<"\n#############################\n# Dump for function "<< asCallee_name <<" #\n#############################\n";
        std::cerr<<"# # Entry dump #\n#\t# top_id #,\t# size(byte) #,\t# type(MSB -- LSB) {} #,\t\t\t# variable name #\n";
        for(std::vector<Entry>::reverse_iterator rit = entries.rbegin();rit!= entries.rend(); ++rit){
            std::cerr<<"#\t"<< rit->top_id <<",\t\t"<< rit->size <<",\t\t"<< std::bitset<32>(rit->type)<<" "<<rit->addr<< ",\t" <<rit->name <<",\n";
        }
        std::cerr<<"\n# # TGenReg dump #\n#\t# regName #,\t# StackID #,\t# type(MSB -- LSB) #\n";
        for(int i=0;i<T_GENERAL_REG_SIZE;++i){
            std::cerr<<"#\t"<< tGenRegName(i) <<",\t\t"<< tGeneralReg[i].id <<",\t\t"<< std::bitset<32>(tGeneralReg[i].type) <<",\n";
        }
        std::cerr<<"\n# instruction dump #\n";
        for(int i=0;i<buffer.size();++i){
            std::cerr<< buffer[i]<<"\n";
        }
        std::cerr<<"\n";
    }

/*
 *  register
 */
    std::string Mp::tGenRegName(int regIdx) {

    if(regIdx<T_GENERAL_REG_SIZE){
            return std::string("$t" + std::to_string(regIdx));
        } else{
            throw std::runtime_error("only support 8 temp reg");
        }
    }

    std::string Mp::tRegName(const RegPtr ptr) {
        int idx; //idx in register file

        // see if idx is general register
        idx=ptr-tGeneralReg;
        if(0<=idx && idx<T_GENERAL_REG_SIZE){
            //is general register
            return tGenRegName(idx);
        }

        // is from co-processor 1 (floating point)
//        idx=ptr-
        throw std::runtime_error("can't find register from ptr");
    }


    bool Mp::discardGenReg(int id) {
        for(int i=0;i<T_GENERAL_REG_SIZE;++i){
            if(tGeneralReg[i].id==id){
                setRegEmpty(tGeneralReg[i].type);
                return true;
            }
        }
        return false;
    }

/*
 * insertion of new variable/arguement
 */

//TODO:: array type
int Mp::reserveArray(Type type, const AddressType& v, std::string identifier) {
    int id = reserveId(sizeOf(type,v), type, identifier,v);
    return id;
}

int Mp::_reserveTempPtr(Type type, const AddressType& v, std::string identifier) {
    int id = reserveId(PTR_SZIE, type, identifier,v);
    return id;
}

int Mp::immediate(int size, std::string data, Type type, std::string identifier) {
    int id = reserveId(size, type, identifier);

    //init value
    if(isFloat(type)){
        //type is single/double float
        throw std::runtime_error("single/double float not supported");
    }else{
        //use general register
        RegPtr regId=findFreeGenReg();
        regId->id=top_id;
        regId->freshness=freshCounter;
        freshCounter++;

        setRegDirty(regId->type);
        _li( tRegName(regId ), data, "imm id _" + std::to_string(id) +"_" );
    }

    return id;
}

int Mp::reserveId(int size, Type type, std::string identifier,const AddressType& address){
        //gen id, allocate space on heap
        top_id+=size;
        entries.push_back({size,top_id,type&CHECK_REG_N ,identifier,address});

        //does not allocate register

        return top_id;
    }

/*
 * Buffers for output assembly
 */

std::string Mp::calOffset(const std::string &str) {//not finished
    int pos=atoi(str.substr(1, str.size()-1).c_str());
    return std::to_string(stack_size-pos); // see my (Ben's) drawing

}

/*
 * Arg passing
 */
//void Mp::addArg(int id) {
//    args.push_back({BY_ID,id,""});
//}
//
//void Mp::addArg_cpArray(int id){
//    throw std::runtime_error("not implemented");
//
//    args.push_back({BY_CP_ARRAY,id,""});
//}
//
//void Mp::addArg_Imm(std::string data){
//    throw std::runtime_error("not implemented");
//
//    args.push_back({BY_IMM,0,data});
//}



/*
 * data modification
 */

    void Mp::writeBackAll() {
        //wire back all general register
        for(int i=0; i<T_GENERAL_REG_SIZE; ++i){
            if( isRegDirty(tGeneralReg[i].type) ){
                sw_sp(tGenRegName(i),tGeneralReg[i].id,"write back id "+std::to_string(tGeneralReg[i].id));
            }
            setRegEmpty(tGeneralReg[i].type);
        }


        //TODO write back all FP register
    }

    int Mp::getId(std::string identifier) {

        //find matching name from top of the stack (itr backwards)
        {
            int i = entries.size() - 1;

            // whill throw out of rang exception if not found
            // todo: need handel global

            while (entries.at(i).name != identifier && i >0){
                --i;
            }

            //if found in current stack frame
            if (i >= 0) {

//                // if is array
//                if (offset != 0) {
//                    if (isArray(entries[i].type) && (entries[i].size > offset)) {
//                        //is array
//                        return entries[i].top_id - offset; //SUB here
//                    } else {
//                        // is not array OR index out of range
//                        throw std::runtime_error(identifier + " is not an array, or index out of range");
//                    }
//                }

                //not array
                return entries[i].top_id;
            }
        }

//        //check if is in parameter (shown as entry with negative id)
//        {
//            int argOffset;
//            Paras::const_iterator it= asCallee_paras.begin();
//            for ( ;it != asCallee_paras.end() && identifier != it->name; ++it ){
//                argOffset += sizeOf(it->type);
//            }
//
//            if(it!=asCallee_paras.end()){
//                // is parameter
//                return -argOffset;
//            }
//        }

        //check if is global
        {

        }

        //undeclared variable
        throw std::runtime_error("undeclared variable "+identifier);



    }

    EntryPtr Mp::getInfo(int id) const {
        int i=0;

        for( ;id>entries[i].size; ++i){
            id-=entries[i].size;
        }

        return &entries[i];

    }

    RegPtr Mp::loadGenReg(int id, bool load) {
        RegPtr regItr=tGeneralReg;


        // check if is already in register
        for (int idx=0; idx<T_GENERAL_REG_SIZE; ++regItr, ++idx ) {
            if (regItr->id == id && !isRegEmpty(regItr->type)) {

                //should not be dirty
                if( isRegUnkown(regItr->type) ){
                    std::cerr<<"[error] *RELOAD* unknown register, id"<< (regItr->id)<<"\n";
                }
                return regItr;
            }
        }

        // if not in register, load from stack

        //load context
        EntryPtr entryPtr=getInfo(id);

        //check context
        if( isFloat(entryPtr->type) ){
            throw std::runtime_error(entryPtr->name+" an single/double float, can not be load to general register");
        }

        // decide which register to use
        regItr=findFreeGenReg();

        // set up reg
        regItr->id = id;
        regItr->type = entryPtr->type;
        regItr->freshness = freshCounter;
        freshCounter++;
        // only load data from stack to register when required to
        if(load){
            lw_sp(tRegName( regItr ), id, "load _"+std::to_string(id) +"_ to" + tRegName( regItr ));
            setRegSync(regItr->type);
        }else{
            setRegUnkown(regItr->type);
        }
        return regItr;

    }

    RegPtr Mp::findFreeGenReg() {
        int least_fresh=freshCounter;
        RegPtr spill_regId;

        // for loop: find empty reg, decide which reg to spill
        RegPtr regId=tGeneralReg;
        for ( int idx=0 ; idx<T_GENERAL_REG_SIZE; ++idx, ++regId) {
            if( isRegEmpty(regId->type) ){
                return regId;

            }else if( !isRegUnkown(regId->type) && (regId->freshness) <least_fresh){
                //prepare if need spill (register in UNKNOW state will not be considered)
                least_fresh=regId->freshness;
                spill_regId=regId;
            }
        }

        //write back if is dirty
        if( isRegDirty(spill_regId->type) ){
            // only write back when is dirty
            sw_sp(tRegName( spill_regId ),spill_regId->id, "spill reg");
        }
        return spill_regId;
    }

//    std::string Mp::readGenReg(int id) {
//        return tGenRegName(loadGenReg(id,true));
//    }
//
//    std::string Mp::writeGenReg(int id) {
//        int regId=loadGenReg(id, false);
//        setRegDirty(tGeneralReg[regId].type); // unknown/dirty/sync state --> dirty state
//        return tGenRegName(regId);
//    }


    /*
     * C instruction
     */
    //
//    void Mp::copyAssign(int dst, int op1, bool free1) {
//        typeDuplicate(dst,op1,free1);
//    }

//    RegPtr Mp::typeDuplicate(Type tDst, int op1, bool free1){
//        EntryPtr e1=getInfo(op1);
////        EntryPtr eDst=getInfo(dst);
//
//        //TODO: BUT, the  line below will NOT work for floating
//
//
//        RegPtr r1= loadGenReg(op1); //TODO, this line need fix, use loadReg()
//        //only write back if value is not freeable AND is dirty
//        if( !free1 && isRegDirty(r1->type) ){
//            sw_sp(tRegName(r1), r1->id, "save dirty register "+std::to_string(r1->id)+" before duplicate");
//            setRegSync(r1->type);
//        }
//
//        if (!isEqual(op1->type, tDst)){
//            //type enforcement, make a copy
//            //cast type from op1 to dst
//            throw std::runtime_error("type enforcement not done");
//
//            int dst=reserveId(sizeOf(tDst), tDst); // make copy
//
//        }
//
//        return r1;//now r1 is dst
//
//    }

    RegPtr Mp::typeDuplicate(int dst, int op1, bool free1){
        EntryPtr e1=getInfo(op1);
        EntryPtr eDst=getInfo(dst);

        //TODO: BUT, the  line below will NOT work for floating
        RegPtr r1= loadGenReg(op1); //TODO, this line need fix
        discardGenReg(dst); //discard dst id even if it is dirty (have not effect for reserved id)

        //only write back if value is not freeable AND is dirty
        if( !free1 && isRegDirty(r1->type) ){
            sw_sp(tRegName(r1), r1->id, "save dirty re _"+std::to_string(r1->id)+"_ before duplicate");
            setRegSync(r1->type);
        }


        //TODO: type check has been commented
            comment("assign _"+std::to_string(r1->id)+"_ to _"+std::to_string(dst)+"_ in reg "+tRegName(r1));
            r1->id=dst;
            setRegDirty(r1->type);
        //TODO: type check has been commented
//        if (!isBasicTypeEqual(e1->type, eDst->type)){
//            //type enforcement
//            //cast type from op1 to dst
//            std::cerr<<"convert "<<std::bitset<32>(e1->type)<<" to "<<std::bitset<32>(eDst->type)<<std::endl;
//            throw std::runtime_error("type enforcement not done");
//
//    //            if()
//
//        }else{
//            //same type, override id
//            comment("assign _"+std::to_string(r1->id)+"_ to _"+std::to_string(dst)+"_ in reg "+tRegName(r1));
//            r1->id=dst;
//            setRegDirty(r1->type);
//        }


        return r1;//now r1 is dst

    }



    void Mp::_algebra(enum_algebra operation, RegPtr dst, RegPtr op1, RegPtr op2, std::string comment) {
        Type resultType=dst->type;

        switch (operation){
            case ADD:
                _addu(tRegName(dst), tRegName(op1), tRegName(op2),comment);
                break;

           case MUL:
               _mul(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               break;

           case DIV:
               if(isUnsignedInt(resultType)){
                 _divu(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               }
               else {
                 _div(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               }
               break;

           case MOD:
               if(isUnsignedInt(resultType)){
                 _modu(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               }
               else{
                 _mod(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               }

               break;

           case SUB:
                _subu(tRegName(dst),tRegName(op1), tRegName(op2),comment);
                break;

           case LEFT_:
               _sll(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               break;

           case RIGHT_:
               if(isUnsignedInt(resultType)){
                 _srl(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               }
               else{
                 _sra(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               }
               break;

           case SMALLER:
               if(isUnsignedInt(resultType)){
                 _sltu(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               }
               else{
                 _slt(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               }
               break;

           case GREATER:
               if(isUnsignedInt(resultType)){
                 _sltu(tRegName(dst),tRegName(op2), tRegName(op1),comment);
               }
               else{
                 _slt(tRegName(dst),tRegName(op2), tRegName(op1),comment);
               }
               break;

           case LE_:
               if(isUnsignedInt(resultType)){
                 _LEu(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               }
               else{
                 _LE(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               }
               break;

           case GE_:
               if(isUnsignedInt(resultType)){
                 _LEu(tRegName(dst),tRegName(op2), tRegName(op1),comment);
               }
               else{
                 _LE(tRegName(dst),tRegName(op2), tRegName(op1),comment);
               }
               break;

           case EQ_:
                 _EQ(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               break;

           case NE_:
                 _NE(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               break;

           case AND:
                 _and(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               break;

           case XOR:
                 _xor(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               break;

           case OR:
                 _or(tRegName(dst),tRegName(op1), tRegName(op2),comment);
               break;

//            case AND_:
//            {
//                Type temp=dst->type;
//                if(isUnsignedInt(temp)||isSignedInt(temp))){
//                _and(tRegName(dst),tRegName(op1), tRegName(op2),comment);
//                }
//                else if(isSingleFloat(temp)){
//                //single floating
//                }
//                else if(isDoubleFloat(temp)){
//                //double floating
//                }
//                else if (isArray(temp)){
//                //array
//                }
//            }
//                break;
//
//            case OR_:
//                //short circuit
//                break;
            default:
                throw std::runtime_error("Not implemented.");
        }

        setRegDirty(dst->type);
    }

    // void Mp::assignment(int dst, std::string constant) {
    //     RegPtr rDst=loadGenReg(dst, false);
    //     setRegDirty(rDst->type);
    //     _li(tRegName(rDst), constant, "assign imm to "+std::to_string(dst));
    // }

    void Mp::assignment(int dst, int op1, enum_assignment operation, bool free){

        // default case for simple assignment
        int _temp=op1;

        switch (operation){
            case MULA: // *=
                _temp=algebra(MUL,dst,op1, false,free,"*="+std::to_string(op1));
                break;

            case DIVA: // /=
                _temp=algebra(DIV,dst,op1, false,free,"/="+std::to_string(op1));
                break;

            case MODA: // %=
                _temp=algebra(MOD,dst,op1, false,free,"%="+std::to_string(op1));
                break;

            case ADDA: // +=
                _temp=algebra(ADD,dst,op1, false,free,"+="+std::to_string(op1));
                break;

            case SUBA: // -=
                _temp=algebra(SUB,dst,op1, false,free,"-="+std::to_string(op1));
                break;

            case LEFTA: // <<=
                _temp=algebra(LEFT_,dst,op1, false,free,"<<="+std::to_string(op1));
                break;

            case RIGHTA: // >>=
                _temp=algebra(RIGHT_,dst,op1, false,free,">>="+std::to_string(op1));
                break;

            case ANDA: // &=
                _temp=algebra(AND,dst,op1, false,free,"&="+std::to_string(op1));
                break;

            case XORA: // ^=
                _temp=algebra(XOR,dst,op1, false,free,"^="+std::to_string(op1));
                break;

            case ORA: // ||=
                _temp=algebra(OR,dst,op1, false,free,"||="+std::to_string(op1));
                break;

        }

        typeDuplicate(dst,_temp,free);

    }


    RegPtr Mp::getAddrOffset(int idxId, bool idxFreeable, EntryPtr array) {
        RegPtr idx, size, final;

        //get sizeOf
        int sizeId = immediate(PTR_SZIE, std::to_string( sizeOf(array->type,array->addr,true) ),TYPE_SIGNED_INT, "size of inner _"+std::to_string(array->top_id)+"_");
        size=loadGenReg(sizeId);

        //get idx
        idx=loadGenReg(idxId);

        //cal offset
        int finalId=reserveId(4,TYPE_SIGNED_INT,"offsets");
        final=loadGenReg(finalId, false);
        _algebra(MUL,final,idx,size,"cal offset _"+std::to_string(finalId));

        if(idxFreeable)
            discardGenReg(idxId);

        return final;

    }


    int Mp::algebra(enum_algebra algebra,int op1, int op2, bool free1, bool free2, std::string varName) {

        RegPtr r1,r2,rResult;
        r1=loadGenReg(op1);
        r2=loadGenReg(op2);

        Type resultType;
        AddressType resultAddrType;


        if(isAddressFlagSet(r1->type)){
            //op1 is ptr
            resultType=r1->type;
            resultAddrType=getInfo(op1)->addr;
            r2 = getAddrOffset( op2,free2, getInfo(op1) );

            //free temp offset
            free2=true;
            op2=r2->id;

        } else if(isAddressFlagSet(r2->type)){
            //op2 is ptr
            resultType=r2->type;
            resultAddrType=getInfo(op2)->addr;
            r1 = getAddrOffset( op1,free1, getInfo(op1) );

            //free temp offset
            free1=true;
            op1=r1->id;

        } else if(isBasicTypeEqual(r1->type,r2->type)){
            // same type
            resultType=r1->type;


        } else{
            // if op1,2 are not ptr and are different => one singed one unsigned
            resultType=TYPE_UNSIGNED_INT;

        }


        // after promotion
        int id_result=reserveId(4,resultType,varName,resultAddrType);
        rResult=loadGenReg(id_result, false);


        //doing actual calculation
        _algebra(algebra, rResult, r1, r2, "dst id _" + std::to_string(id_result) + "_");

        //free op register
        if(free1){
            discardGenReg(op1);
        }

        if(free2){
            discardGenReg(op2);
        }

        return id_result;

    }

    int Mp::addi(bool perfix, int op1, std::string integer) {
        RegPtr r1;
        r1=loadGenReg(op1);



        if(perfix){
            //per increment
            _addi(tRegName(r1), tRegName(r1), integer, "per increment of id _"+std::to_string(op1)+"_");
            setRegDirty(r1->type);
            return op1;

        } else{
            //if if post increment, return a copy before increment

            int orgCopy;
            RegPtr rOrgCopy;

            orgCopy=reserveId(4,r1->type,"org copy of _"+std::to_string(op1)+"_");
            rOrgCopy=loadGenReg(orgCopy, false);

            _addi(tRegName(rOrgCopy), tRegName(r1), integer, "add, swap org copy & org");

            r1->id=orgCopy;
            rOrgCopy->id=op1;

            setRegDirty(r1->type);
            setRegDirty(rOrgCopy->type);

            return orgCopy;
        }
    }

    int Mp::negation(char type, int op1, bool free1){
      RegPtr r1;
      int Copy;
      r1=loadGenReg(op1);
      if(!free1 && isRegDirty(r1->type)){
        sw_sp(tRegName(r1), r1->id, "save dirty re _"+std::to_string(r1->id)+"_ before negation");
        setRegSync(r1->type);
      }
      Copy=reserveId(4,r1->type,"negating copy of_"+std::to_string(op1)+"_" );
      switch(type){
        case '-':
          _subu(tRegName(r1),"$0",tRegName(r1),"negating_"+std::to_string(op1)+"_");
          //checked with godbolt
        break;
        case '~':
          _nor(tRegName(r1),"$0",tRegName(r1),"nor_"+std::to_string(op1)+"_");
        break;
        case '!':
          _sltu(tRegName(r1),tRegName(r1),"1","sltu_"+std::to_string(op1)+"_");
          _and(tRegName(r1),tRegName(r1),"0x00ff","andi_0x00ff"+std::to_string(op1)+"_");
          break;
        default:
          throw std::runtime_error("Not implemented.");
      }
      r1->id=Copy;
      setRegDirty(r1->type);
      return Copy;
    }

//    int Mp::makeCopy(int id, bool free1) {
//        EntryPtr info=getInfo(id);
//        int resultId;
//
//        int size = isDoubleFloat(info->type) ? 8 : 4 ;
//        resultId=reserveId(size,info->type,"was copy of "+std::to_string(id));
//
//        typeDuplicate(resultId,id,free1);
//
//        return resultId;
//    }


    /*
            } else{
     * make function calls
     */

    void Mp::callFunc(const std::string &funcName) {

        asCaller_name=funcName;
        paraIdx=1;
        para_offset=0;


        Functions::const_iterator asCaller;
        implicitCall = context.getFunc(funcName, asCaller); //have side effect

        if(implicitCall){
            context.addFunc(funcName, TYPE_SIGNED_INT); //implicit function declaration
        } else{
            asCaller_args=asCaller->second;
        }

    }

    void Mp::addArg(int id) {
        //todo only work for int

//        EntryPtr info=getInfo(id);
        RegPtr reg;

        if(implicitCall){
            // convert GPR -> INT
            // convert CP! -> DOUBLE
            reg=loadGenReg(id);

            context.addFuncPara(TYPE_SIGNED_INT,"");

            if(para_offset<16){
                _move("$a"+std::to_string(para_offset/4), tRegName(reg), "implicit call, int type");
            }else{
                sw_sp(tRegName(reg),std::to_string(para_offset),"implicit call, int type");
            };



            para_offset+=sizeOf(reg->type);

        }else{
            reg=loadGenReg(id);

            if(para_offset<16){
                _move("$a"+std::to_string(para_offset/4), tRegName(reg), "implicit call, int type");
            }else{
                sw_sp(tRegName(reg),std::to_string(para_offset),"implicit call, int type");
            };

            para_offset+=sizeOf(reg->type);

        }



    }


    int Mp::commitCall() {
        int resultId;

        //update system state
        if(implicitCall){
            // commit implicit function declaration
            context.commitFunc();
        }

        //save all reg before calls
        writeBackAll();

        //JAL to function
        _jal(asCaller_name);

        //get return result
        if(implicitCall || !isFloat(asCaller_args[0].type)){
            // in GPR
            Type returnType = implicitCall ? TYPE_SIGNED_INT : asCaller_args[0].type;
            resultId=reserveId(4,returnType,asCaller_name+" return");
            RegPtr rReg= loadGenReg(resultId, false);
            _move(tRegName(rReg), "$v0", "mv return to tReg _"+std::to_string(resultId)+"_");
            setRegDirty(rReg->type);

        }else{
            //in cp1

        }

        if(para_offset>arg_max_size)
            arg_max_size=para_offset;

        return resultId;

    }



    /*
     * current function
     */
    std::string Mp::mkLabel(const std::string &name) {
        std::string label = name + "_"+std::to_string(uniqueCounter)+"_"+asCallee_name;
        ++uniqueCounter;
        return label;
    }

    void Mp::insertLabel(const std::string &label) {
        buffer.push_back(label + ":\n");
    }

    void Mp::Return(int id) {

        //TODO: get return type
        Type returnType=asCallee_paras[0].type;


        int dst = reserveId(sizeOf(returnType),returnType, "FUNC RETURN");
        RegPtr _op1 = typeDuplicate(dst, id, true); // not sure (think is true, because frame will be popped )
        std::string _op1Str=tRegName(_op1);

        if(isFloat(returnType)){
            if(isDoubleFloat(returnType)){
                buffer.push_back("mov.d $f0, " + _op1Str);
            }else{
                buffer.push_back("mov.s $f0, " + _op1Str);
            }
        }else {
            buffer.push_back("move $2," + _op1Str);
        }

        _b(RETURN_LABEL);
    }

    void Mp::Return(){
        _b(RETURN_LABEL);
    }

    /*
     *  BLOCK control
     */

    void Mp::bZero(bool onTrue, int id, std::string label) {
        EntryPtr entry=getInfo(id);

        if(isFloat(entry->type)){
            //is on cp1
            throw std::runtime_error("Not implemented.");
        }else{
            //is on genReg
            RegPtr reg=loadGenReg(id);
            if(onTrue){
                //branch on true (on 1, -ne $0)
                _bne(tRegName(reg), "$0", label );
            }else{
                //branch on false (on 0, -eq $0)
                _beq(tRegName(reg), "$0", label );
            }
        }
    }

  void Mp::branch(std::string label){
    _b(label);
  }

  void Mp::beq(int id1,int id2,std::string label){
    EntryPtr entry1=getInfo(id1);
    EntryPtr entry2=getInfo(id2);
    //TODO check both ?
    if(isFloat(entry1->type)||isFloat(entry2->type)){
        //is on cp1
        throw std::runtime_error("Not implemented.");
    }else{
        //is on genReg
        RegPtr reg1=loadGenReg(id1);
        RegPtr reg2=loadGenReg(id2);
        _beq(tRegName(reg1),tRegName(reg2),label);
      }
    }
