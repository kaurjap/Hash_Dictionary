// HashTable.cpp

#include <iostream>
#include <sstream>
#include "HashTable.h"


HashTable::HashTable() {
    // initialize every slot in the vector to contain an empty linked list
    // std::shared_ptr<LLDataNode> linkedlist = std::make_shared<LLDataNode>();
    array = std::vector< std::shared_ptr<LLDataNode> >(26);
    
//    for (int i = 0; i < 26; i++) {
//        array.at(i) = linkedlist;
//    } // end for
} // end constructor


int HashTable::hashFunction(std::string key) {
    // the key is the first two letters of the word to find the hash code of
    // if the word is only 1 letter long, then, key is only the first letter
    // But I am finding the hash code based on the first letter only
    // all words with the same first letter hash to the same slot in the hash table in a chain (linked list)
    // the key coming in should be lowercase
    char k = key[0];
    // start the hash code
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
    // find the hashed index to look up the key at
    int hashCode;
    hashCode = hashFunction(word->getKey());
    // look the key up in the hashed slot
    // each item in the array is a linked list
    std::shared_ptr<LLDataNode> currentLinkedList = std::make_shared<LLDataNode>();
    currentLinkedList = array[hashCode];
    resultingNodes result;
    result = currentLinkedList->search(word);
    if (result.wordExists) {
        std::cout << "True" << std::endl;
        std::cout << "Exact word found: " << result.word << std::endl;
    } else {
        std::cout << "False" << std::endl;
    } // end if-else
    
    // print similar words if there are any
    if (result.similarWords.size() != 0) {
        std::cout << "Similar words found: " << std::endl;
        for (int i = 0; i < result.similarWords.size(); i++) {
            std::cout << result.similarWords[i] << std::endl;
        } // end for
    } // end if
    else {
        std::cout << "No similar words found either." << std::endl;
    } // end else
} // end search

