//
// Created by IsaacAP on 2019-10-30.
//
#include "test.h"

///Recursive Function Demonstration
///\param integer
///\return integer
int recursive(int i){
    if(i ==0)return 1;

    return i*recursive(i-1);
}