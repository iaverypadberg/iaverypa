//
// Created by IsaacAP on 2019-10-30.
//

#ifndef TESTING_TEST_H
#define TESTING_TEST_H


#include <vector>
#include <string>
//Defining your own namespace allows you to have identical variable names in main an in test but with different values
//std::int val
//vs
//test::int val
namespace test {

//All function definitions belong here
    int recursive(int i);

    static const std::vector<std::string> wordList;
#endif //TESTING_TEST_H


}