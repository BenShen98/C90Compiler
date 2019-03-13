//
// Created by ben on 2019/3/6.
//

#include "Mp.hpp"

#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <stdexcept>
#include <regex>
#include <fstream>

#define RETURN_LABEL "EXIT_"+funcName

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
        entries = std::vector<Entry>(1,{0,0,TYPE_SIGNED_INT,""});

        //reset function name
        arg_top_id=0;
        funcName=name;
    //    args.clear();
    //    arg_top_id=0;

    }

    /*
     * flush data
     */
    void Mp::endFrame(bool logging) {

        //calculate zone for `local and temporaries` and `args`
        arg_top_id=16; //assume no arguement
        stack_size = top_id + 4 + arg_top_id; // space for {local},$RA, {opt_place_holder}, {arg_list}

        if(stack_size&0x4){
            stack_size+=4; //make stack frame 8 byte aligned
        }

        //write back dirty register (not needed, for test only)
        writeBackAll();

/*
 * flush buffer
 */
        // frame setup
        ffout<<"addiu $sp, $sp, -"<<stack_size<<'\n'; // allocate stack
        ffout<<"sw $31, "<<arg_top_id<<"($sp)"<<'\n';

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
                ffout<<m.prefix()<<calOffset(m[0])<<m.suffix();

                //increment id
                ++editIdx;
            }else{
                ffout<<buffer[bufIdx];
            }
        }

        //iteration when reached end of postEditPtr
        for( ; bufIdx<buffer.size();++bufIdx){
                ffout<<buffer[bufIdx];
        }

        //frame delete
        ffout<<std::string(RETURN_LABEL)<<":\n";
        ffout<<"lw $31, "<<arg_top_id<<"($sp)"<<'\n';
        ffout<<"addiu $sp, $sp, "<<stack_size<<'\n'; // deallocate stack
        ffout<<"j $31\n";

        //logging and exit
        if(logging)
            dump();

        funcName="";
        delete[] tGeneralReg;


    }

    void Mp::dump() {

        std::cerr<<"\n#############################\n# Dump for function "<< funcName <<" #\n#############################\n";
        std::cerr<<"# # Entry dump #\n#\t# top_id #,\t# size(byte) #,\t# type(MSB -- LSB) #,\t\t\t# variable name #\n";
        for(std::vector<Entry>::reverse_iterator rit = entries.rbegin();rit!= entries.rend(); ++rit){
            std::cerr<<"#\t"<< rit->top_id <<",\t\t"<< rit->size <<",\t\t"<< std::bitset<32>(rit->type)<< ",\t" <<rit->name <<",\n";
        }
        std::cerr<<"\n# # TGenReg dump #\n#\t# regName #,\t# StackID #,\t# type(MSB -- LSB) #\n";
        for(int i=0;i<T_GENERAL_REG_SIZE;++i){
            std::cerr<<"#\t"<< tGenRegName(i) <<",\t\t"<< tGeneralReg[i].id <<",\t\t"<< std::bitset<32>(tGeneralReg[i].type) <<",\n";
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
        _li( tRegName(regId ), data, "immediate " + identifier);
    }

    return id;
}

int Mp::reserveId(int size, Type type, std::string identifier){
        //gen id, allocate space on heap
        top_id+=size;
        entries.push_back({size,top_id,type,identifier});

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
                setRegDirty(tGeneralReg[i].type);
            }
        }


        //TODO write back all FP register
    }

    int Mp::getId(std::string identifier, int offset) {
        //find matching name from top of the stack (itr backwards)
        int i =entries.size()-1;

        // whill throw out of rang exception if not found
        while (entries.at(i).name!=identifier){
            --i;
        }

        if(offset!=0){
            if( isArray(entries[i].type) && (entries[i].size>offset) ){
                //is array
                return entries[i].top_id - offset; //SUB here
            } else{
                // is not array OR index out of range
                throw std::runtime_error(identifier+" is not an array, or index out of range");
            }
        }

        //not array
        return entries[i].top_id;
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
            if (regItr->id == id) {

                //should not be dirty
                if( isRegUnkown(regItr->type) ){
                    std::cerr<<"[error] *REload* unknown register, id"<< (regItr->id)<<"\n";
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
            lw_sp(tRegName( regItr ), id, "load "+entryPtr->name);
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

    int Mp::sizeOf(Type type) {
        if( isDoubleFloat(type) ){
            //only double is 8 byte
            return 8;
        }else{
            //all other is 4 byte wide (ptr, int, float, etc
            return 4;
        }
    }

    /*
     * C instruction
     */
    //
    RegPtr Mp::typeDuplicate(int dst, int op1){
        EntryPtr e1=getInfo(op1);
        EntryPtr eDst=getInfo(dst);

        //TODO: BUT, the  line below will NOT work for floating
        RegPtr r1= loadGenReg(op1); //TODO, this line need fix

        if( isRegDirty(r1->type) ){
            sw_sp(tRegName(r1), r1->id, "save dirty register "+std::to_string(r1->id)+" before duplicate");
            setRegSync(r1->type);
        }

        if (!isBasicTypeEqual(op1->type, dst->type)){
            //type enforcement
            //cast type from op1 to dst
            throw std::runtime_error("type enforcement not done");

            if()

        }else{
            //same type, override id
            r1->id=dst;
        }


        return r1;//now r1 is dst

    }

    std::pair<RegPtr , RegPtr> Mp::typePromotion(int op1, int op2) {
        EntryPtr e1=getInfo(op1);
        EntryPtr e2=getInfo(op2);


        if( !isBasicTypeEqual(e1->type, e2->type) ){
            //type promotion
            //..../
            throw std::runtime_error("type promotion not done");

        }else{

            //no type promotion
            if( isFloat(e1->type) ){
                throw std::runtime_error("single/double float not supported");

            }else{
                return std::make_pair( loadGenReg(op1), loadGenReg(op2) );
            }
        }

    }


    int Mp::algebra(enum_algebra algebra,int op1, int op2, bool free1, bool free2, std::string comment) {

        RegPtr r1, r2,rResult;
        std::pair<RegPtr, RegPtr> afterPromotion = typePromotion(op1,op2);
        r1=afterPromotion.first;
        r2=afterPromotion.second;

        int resultId;


        if(isDoubleFloat(r1->type)){

        }else{
            int resultId=reserveId(4,r1->type,comment);
            rResult=loadGenReg(resultId, false);
        }

        switch (algebra){
            case ADD:
                _addu(tRegName(rResult), tRegName(r1), tRegName(r2),comment);
                break;
//            case MUL:
//                break;
//
//            case DIV:
//                break;
//
//            case MOD:
//                break;
//
//            case SUB:
//                break;
//
//            case LEFT_:
//                break;
//
//            case RIGHT_:
//                break;
//
//            case SMALLER:
//                break;
//
//            case GREATER:
//                break;
//
//            case LE_:
//                break;
//
//            case GE_:
//                break;
//
//            case EQ_:
//                break;
//
//            case NE_:
//                break;
//
//            case AND:
//                break;
//
//            case XOR:
//                break;
//
//            case OR:
//                break;
//
//            case AND_:
//                //short circuit
//                break;
//
//            case OR_:
//                //short circuit
//                break;
//
            default:
                throw std::runtime_error("Not implemented.");
        }

        setRegDirty(rResult->type);

        //free extra register caused by promotion
        if( r1->id != op1 ){
            discardGenReg(r1->id);
        }

        if( r2->id != op1 ){
            discardGenReg(r2->id);
        }

        //free op register
        if(free1){
            discardGenReg(op1);
        }

        if(free2){
            discardGenReg(op2);
        }

        return resultId;

    }

    int Mp::addi(bool selfAssign, int op1, std::string integer,bool free1, std::string comment) {
        RegPtr r1,rResult;
        r1=loadGenReg(op1);

        int resultId;

        if(selfAssign){
            rResult=r1;
            resultId=op1;
        } else{
            int resultId=reserveId(4,op1->type,comment);
            rResult=loadGenReg(resultId, false);
        }


        _addiu(tRegName(rResult), tRegName(r1), integer, comment);

        setRegDirty(rResult->type);

        if( !selfAssign && free1){
            //ignore free flag if is self assign
            discardGenReg(op1);
        }

        return resultId;
    }

    int Mp::makeCopy(int id) {
        EntryPtr info=getInfo(id);
        int resultId;

        int size = isDoubleFloat(info->type) ? 8 : 4 ;
        resultId=reserveId(size,info->type,"was copy of "+std::to_string(id));

        typeDuplicate(resultId,id;)

        return resultId;
    }


    /*
     * make function calls
     */



    /*
     * current function
     */
    std::string Mp::mkLable(const std::string &name) {
        std::string label = name + "_"+std::to_string(uniqueCounter)+"_"+funcName;
        buffer.push_back(label + ":\n");
        ++uniqueCounter;
        return label;
    }

    void Mp::Return(){
        _b(RETURN_LABEL);
    }
