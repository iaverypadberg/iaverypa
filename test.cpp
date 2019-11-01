//
// Created by IsaacAP on 2019-10-30.
//
#include "test.h"
#include "MyException.h"
#include "MyException.h"
#include <iostream>

/**
 * Recursive Function Demonstration
 *
 * @param integer
 * @return integer
 */
int test::recursive(int i){
    if(i ==0)return 1;

    return i*recursive(i-1);
}

/**
 * Calculates a phrase for given entropy index list
 *
 * @param wordListIndices indicies from entropy
 * @return string containing the phrase
 */
std::vector<std::string> test::indexListToPhrase(std::vector<int> indexList) {
    //Make vector for mnemonic phrase
    std::vector<std::string> phrase;

        //Throw exception if indexList is empty
        if (indexList.empty()) {
            throw MyException();
        }

        //loop through indices and add correlating index to phrase vector
        for (int i = 0; i < indexList.size(); i++) {

            //Throw exception if index is larger than wordList
            if (indexList.at(i)> 2047)
                throw MyException();

            //Throw exception if index is smaller than wordList
            if (indexList.at(i)< 0)
                throw MyException();
            phrase.emplace_back(wordList.at(indexList.at(i)));
        }


        return phrase;


}
/**
 * recursively implemented binarySearch which takes in a sorted array and returns the index of the number found
 * If not found it will return -1
 * If input vector is empty it will throw and exception
 *
 * @param integer searching for
 * @param sortedIntegers vector
 * @return found integer
 */
int test::binarySearch(std::vector<int> sortedIntegers, int target, int left, int right) {

    //Kill phrase
    if(right>=left) {
        //Input cannot be empty
        if (sortedIntegers.empty())
            throw MyException();

        //Create a mid integer so that it is always shifting with with the left and right
        int mid = left + (right - left) / 2;

        //If target is in the middle return it
        if (target == sortedIntegers[mid])
            return mid;

        //If target is to the left of middle
        if (target < sortedIntegers[mid])
            return binarySearch(sortedIntegers, target, left, mid - 1);

        //Then target is to the right of middle
        return binarySearch(sortedIntegers, target, mid + 1, right);
    }
    return -1;

}
