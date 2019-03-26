#ifndef ast_algebra
#define ast_algebra

#include "_ast_abs.hpp"
#include "algebra_enum.hpp"

#include <string>
/*
* When there is only signal element in the tree, that element get promoted
* e.g. multiplicative_expression:cast_expression  => {$$=$1}
*
*
multiplicative_expression
: cast_expression
| multiplicative_expression '*' cast_expression
| multiplicative_expression '/' cast_expression
| multiplicative_expression '%' cast_expression
;

additive_expression
: multiplicative_expression
| additive_expression '+' multiplicative_expression
| additive_expression '-' multiplicative_expression
;

shift_expression
: additive_expression
| shift_expression LEFT_OP additive_expression
| shift_expression RIGHT_OP additive_expression
;

relational_expression
: shift_expression
| relational_expression '<' shift_expression
| relational_expression '>' shift_expression
| relational_expression LE_OP shift_expression
| relational_expression GE_OP shift_expression
;

equality_expression
: relational_expression
| equality_expression EQ_OP relational_expression
| equality_expression NE_OP relational_expression
;

and_expression
: equality_expression
| and_expression '&' equality_expression
;

exclusive_or_expression
: and_expression
| exclusive_or_expression '^' and_expression
;

inclusive_or_expression
: exclusive_or_expression
| inclusive_or_expression '|' exclusive_or_expression
;

logical_and_expression
: inclusive_or_expression
| logical_and_expression AND_OP inclusive_or_expression
;

logical_or_expression
: logical_and_expression
| logical_or_expression OR_OP logical_and_expression
;

*/


class algebra: public ast_abs{
    enum_algebra type;
    astPtr left;
    astPtr right;

public:
    algebra(enum_algebra t, astPtr l, astPtr r):type(t),left(l),right(r){}

    ~algebra() override{
        delete right;
        delete left;
    }

    virtual void py(std::string& dst) const override{
        std::string r,l;
        right->py(r);
        left->py(l);

        switch (type){
            //brackets are redundant but just in case
            case MUL:
                dst = '(' +  l + '*' + r + ')';
                break;

            case DIV:
                dst = '(' +  l + '/' + r + ')';
                break;

            case MOD:
                dst = '(' +  l + '%' + r + ')';
                break;

            case ADD:
                dst = '(' +  l + '+' + r + ')';
                break;

            case SUB:
                dst = '(' +  l + '-' + r + ')';
                break;

            case LEFT_:
                dst = '(' +  l + "<<" + r + ')';
                break;

            case RIGHT_:
                dst = '(' +  l + ">>" + r + ')';
                break;

            case SMALLER:
                dst = '(' +  l + '<' + r + ')';
                break;

            case GREATER:
                dst = '(' +  l + '>' + r + ')';
                break;

            case LE_:
                dst = '(' +  l + "<=" + r + ')';
                break;

            case GE_:
                dst = '(' +  l + ">=" + r + ')';
                break;

            case EQ_:
                dst = '(' +  l + "==" + r + ')';
                break;

            case NE_:
                dst = '(' +  l + "!=" + r + ')';
                break;

            case AND:
                dst = '(' +  l + '&' + r +  ')';
                break;

            case XOR:
                dst = '(' +  l + '^' + r + ')';
                break;

            case OR:
                dst = '(' +  l + '|' + r + ')';
                break;

            case AND_:
                dst = '(' +  l + "and" + r + ')';
                break;

            case OR_:
                dst = '(' +  l + "or" + r + ')';
                break;
        }

    }

    virtual void mp(Result& result) const override{

        Result op1,op2;

        if(!isVoid(result.type)){

            if( type==AND_ ){
                //short circuit AND &&
                result.id=mips.reserveId(4,TYPE_SIGNED_INT,"bool ");
                RegPtr rResult=mips.loadGenReg(result.id, false);
                std::string ANDShort=mips.mkLabel("ANDShort");
                std::string ANDEnd=mips.mkLabel("ANDEnd");

                left->mp(op1);
                mips._beq(mips.tRegName(mips.loadGenReg(op1.id)),"$0",ANDShort);

                right->mp(op2);
                mips._beq(mips.tRegName(mips.loadGenReg(op2.id)),"$0",ANDShort);

                rResult=mips.loadGenReg(result.id); //update rResult ptr, in case changed by other code
                mips._li(mips.tRegName(rResult),"1");
                setRegDirty(rResult->type);
                mips.writeBackReg(result.id, true);
                mips._b(ANDEnd);

                rResult=mips.loadGenReg(result.id); //update rResult ptr, in case changed by other code
                mips.insertLabel(ANDShort);
                mips._move(mips.tRegName(rResult),"$0");
                setRegDirty(rResult->type);
                mips.writeBackReg(result.id, true);

                mips.insertLabel(ANDEnd);

            }else if( type==OR_ ){
                //short circuit OR ||
                result.id=mips.reserveId(4,TYPE_SIGNED_INT,"bool ");
                RegPtr rResult=mips.loadGenReg(result.id);
                std::string ORShort=mips.mkLabel("ORShort");
                std::string OREnd=mips.mkLabel("OREnd");

                left->mp(op1);
                mips._bne(mips.tRegName(mips.loadGenReg(op1.id)),"$0",ORShort);

                right->mp(op2);
                mips._bne(mips.tRegName(mips.loadGenReg(op2.id)),"$0",ORShort);

                rResult=mips.loadGenReg(result.id); //update rResult ptr, in case changed by other code
                mips._move(mips.tRegName(rResult),"$0");
                setRegDirty(rResult->type);
                mips.writeBackReg(result.id, true);
                mips._b(OREnd);

                rResult=mips.loadGenReg(result.id); //update rResult ptr, in case changed by other code
                mips.insertLabel(ORShort);
                mips._li(mips.tRegName(rResult),"1");
                setRegDirty(rResult->type);
                mips.writeBackReg(result.id, true);


                mips.insertLabel(OREnd);

            }else{

                    left->mp(op1);
                    right->mp(op2);


                result.id = mips.algebra( op1.isIndirection||op2.isIndirection ,type, op1.id, op2.id, op1.freeable, op2.freeable,"=op(" + std::to_string(type) + ") " + op1.id.str() + " " + op2.id.str() );
                result.freeable= true; //this is indeterminate result, no need to store


            }

        }else{
            // compile time constant

            op1.type=TYPE_VOID;
            op2.type=TYPE_VOID;
            left->mp(op1);
            right->mp(op2);

            switch (type){
                //brackets are redundant but just in case
                case MUL:
                    result.num =  op1.num * op2.num;
                    break;

                case DIV:
                    result.num =  op1.num / op2.num;
                    break;

                case MOD:
                    result.num =  op1.num % op2.num;
                    break;

                case ADD:
                    result.num =  op1.num + op2.num;
                    break;

                case SUB:
                    result.num =  op1.num - op2.num;
                    break;

                case LEFT_:
                    result.num =  op1.num << op2.num;
                    break;

                case RIGHT_:
                    result.num =  op1.num >> op2.num;
                    break;

                case SMALLER:
                    result.num =  op1.num < op2.num;
                    break;

                case GREATER:
                    result.num =  op1.num > op2.num;
                    break;

                case LE_:
                    result.num =  op1.num <= op2.num;
                    break;

                case GE_:
                    result.num =  op1.num >= op2.num;
                    break;

                case EQ_:
                    result.num =  op1.num == op2.num;
                    break;

                case NE_:
                    result.num =  op1.num != op2.num;
                    break;

                case AND:
                    result.num =  op1.num & op2.num;
                    break;

                case XOR:
                    result.num =  op1.num ^ op2.num;
                    break;

                case OR:
                    result.num =  op1.num | op2.num;
                    break;

                case AND_:
                    result.num =  op1.num && op2.num;
                    break;

                case OR_:
                    result.num =  op1.num || op2.num;
                    break;
            }


        }


    }

};

#endif
