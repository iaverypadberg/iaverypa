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

/**
 * printArray: A small printing function for the vector
 *
 * @param vector
 * @param size
 */
void test::printArray(std::vector<int>* vector, int size) {

    std::cout<<"[";
    for(int i=0;i<size;i++) {
        std::cout << vector->at(i);
        std::cout << ",";
    }
    std::cout<<"]\n";

}


/**
 * implementQuickSort: structures the output and starts the first recursive call of the quickSort algorithm
 *
 * @param toBeSorted is the pointer to the vector that will be sorted
 */
void test::implementQuickSort(std::vector<int>* toBeSorted) {

    //Get and store the size of the vector in a
    int a = toBeSorted->size();

    //Print out unsorted vector
    std::cout<<"Here is the unsorted vector: ";
    test::printArray(toBeSorted,a);
    //Call quickSort function

    test::quickSort(toBeSorted,0,a-1);///FIXME unsigned long in type int(might need to add a -1)
    //Print out the sorted vector
    std::cout<<"Here is the sorted vector: ";
    test::printArray(toBeSorted,a);

}

/**
 * quickSort: Recursively sorts vector by splitting the vector into smaller pieces using
 * the function call paritition
 *
 * @param high: Largest index in vector
 * @param low: Smallest index in vector
 */
void test::quickSort(std::vector<int>* unsortedVector, int low, int high) {

    //Once this is false the recursion is done
    if(low<high){

        //p is in the right place
        int p = test::paritition(unsortedVector,low,high);

        //recursively sort the rest of the elements now that p is in the right spot
        test::quickSort(unsortedVector, low,p-1);
        test::quickSort(unsortedVector,p+1,high);
    }

}
/**
 * Paritition: Last element is pivot. Pivot will be in its final resting place.
 * Smaller elemets are placed to the left of the pivot and larger
 * elements are placed to the right.
 *
 * @param unsortedVec: Pointer to the unsorted vector
 * @param low: Lowest index
 * @param high: Highest index
 * @return integer: resting place of pivot
 */
int test::paritition(std::vector<int>*unsortedVector, int low, int high) {

    //Assign pivot to the end of the vector
    int pivot = unsortedVector->at(high);

    int i = (low - 1);
    //Loop through each element until 1 before the pivot value
    for (int j = low; j <= high-1; j++) {
        //If the value at the incremented index J is smaller than the pivot value, increment I and then swap the
        //values at J and I
        if (unsortedVector->at(j) < pivot) {
            i++;
            swap(&unsortedVector->at(i), &unsortedVector->at(j));
        }
    }
    //Once the end of the loop is reached place the pivot in between the values
    //that are smaller(I) and the rest of the values
    swap(&unsortedVector->at(i+1),&unsortedVector->at(high));
    return(i+1);

}
/**
 *Swap: swaps position of i and x in vector
 *
 * @param i
 * @param x
 */
void test::swap(int* i, int* x){

    int temp = *i;
    *i = *x;
    *x=temp;

}
