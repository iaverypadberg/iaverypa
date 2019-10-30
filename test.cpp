//
// Created by IsaacAP on 2019-10-30.
//
#include "test.h"
#include "MyException.h"
#include "MyException.h"

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
            if (indexList.at(i) > 2047)
                throw MyException();

            //Throw exception if index is smaller than wordList
            if (indexList.at(i) < 0)
                throw MyException();
            phrase.emplace_back(wordList.at(indexList.at(i)));
        }


        return phrase;




}
