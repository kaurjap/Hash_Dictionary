// HashTable.cpp

#include <sstream>
#include "HashTable.h"
#include "TimeInterval.h"


HashTable::HashTable() {
    // initialize every slot in the vector to contain an empty linked list
    array = std::vector< std::shared_ptr<LLDataNode> >(26);
    for (int i = 0; i < 26; i++) {
        array.at(i) = std::make_shared<LLDataNode>();
    } // end for
} // end constructor


int HashTable::hashFunction(std::string key) {
    // key to hash is the first letter of a word
    // all words with the same first letter hash to the same slot in the hash table in a chain (linked list)
    // the key coming in should be lowercase
    char k = key[0];
    // getting the ascii value of the first letter and finding the remainder of its division by 26
    int hashCode;
    hashCode = (int(k) + 7) % 26;
    return hashCode;
} // end hashFuncton


void HashTable::insert(std::shared_ptr<DataNode> node) {
    // node has a key and value associated with it
    // hash the key first
    int index;
    index = hashFunction(node->getKey());
    // insert the node in the index (th) linked list in the array 
    array[index]->insert(node);
} // end insert


void HashTable::search(std::shared_ptr<DataNode> word) {
    TimeInterval timer;
    // start the timer
    timer.start();
    // find the hashed index to look up the key at
    int hashCode;
    hashCode = hashFunction(word->getKey());
    // look the key up in the hashed slot
    // each item in the array is a linked list
    std::shared_ptr<LLDataNode> currentLinkedList = std::make_shared<LLDataNode>();
    currentLinkedList = array[hashCode];
    resultingNodes result;
    result = currentLinkedList->search(word);
    
    // searching has been performed, hence, stop the timer
    timer.stop();
    
    // print the results from the search
    if (result.wordExists) {
        std::cout << "\nTrue" << std::endl;
    } else {
        std::cout << "\nFalse." << std::endl;
    } // end if-else
    
    // print similar words if there are any
    if (result.similarWords.size() != 0) {
        std::cout << "\n*********************\nSimilar words found: " << std::endl;
        for (unsigned int i = 0; i < result.similarWords.size(); i++) {
            std::cout << result.similarWords.at(i) << std::endl;
        } // end for
        std::cout << "***********************\n";
    } // end if
    else {
        std::cout << "\n*********************\nNo similar words found.\n*********************\n" << std::endl;
    } // end else
    
    // printing the time interval
    std::cout << "Execution Time: " << timer.GetInterval() << " micro-sec\n" << std::endl;
} // end search


std::vector< std::shared_ptr<LLDataNode> > HashTable::getArray() {
    return array;
} // end getArray