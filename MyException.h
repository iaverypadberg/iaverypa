//
// Created by IsaacAP on 2019-10-30.
//

#ifndef TESTING_MYEXCEPTION_H
#define TESTING_MYEXCEPTION_H

#include <exception>
#include <iostream>


class MyException : public std::exception{

public:
    int index;
    bool empty;
    const char* what(){
        std::cout<<"ERROR \n";
    }
    void outOfBounds(){
        std::cout<<"You have entered a value out of bounds\n";
    }
    void setIndex(int index){
        this->index=index;
    }
    void isEmpty(bool empty){
        this->empty=empty;
        if(empty)
            std::cout<<"The indexList entered is empty\n";
    }
};


#endif //TESTING_MYEXCEPTION_H
