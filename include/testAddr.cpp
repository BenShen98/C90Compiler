//
// Created by ben on 2019/2/20.
//
#include <iostream>
#include <string>

#include "Mp_Type.hpp"

/*
 * Tree for C code below (default int)
 *
 * main(){
 *      int x=1;
 *      return x;
 * }
 */



int main(){
    Type t=TYPE_SIGNED_INT;
    setAddressFlag(t);
    AddressType v= {3,-1,7,5}; //type of int (*A[5][7])[3]
    std::cout<< sizeOf(t,v)<<" "<<isAddressFlagSet(t)<<" "<<v<<"\n";

    deference(t,v);
    std::cout<< sizeOf(t,v)<<" "<<isAddressFlagSet(t)<<" "<<v<<"\n";

    deference(t,v);
    std::cout<< sizeOf(t,v)<<" "<<isAddressFlagSet(t)<<" "<<v<<"\n";

    deference(t,v);
    std::cout<< sizeOf(t,v)<<" "<<isAddressFlagSet(t)<<" "<<v<<"\n";

    deference(t,v);
    std::cout<< sizeOf(t,v)<<" "<<isAddressFlagSet(t)<<" "<<v<<"\n";

    deference(t,v);
    std::cout<< sizeOf(t,v)<<" "<<isAddressFlagSet(t)<<" "<<v<<"\n";

}