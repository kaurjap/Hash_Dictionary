// DataNode.cpp

#include "DataNode.h"

DataNode::DataNode() {
    data = "";
    key = "";
    next = nullptr;
} // end constructor

DataNode::DataNode(std::string word) {
    data = word;
    // update the key based on the new word inserted
    key = setKey();
    next = nullptr;
} // end parameterized constructor


/* Function: setKey
 * Purpose: to update the value of the word's key based on the value of the data (the word itself) when it is updated
 *          the key is either only the first letter or the first two letters based on the length of the string 
 * Return value: the string for key
 */
std::string DataNode::setKey() {
    std::string key;
    key = "";
    if (data.size() >= 1) {
        // use the substring method to get the first two letters of the word as key
        if (data.size() > 2) {
            key = data.substr(0, 2); // from position = 0 and length = 2
        } // end if
        else {
            key = data;
        } // end if-else
    } // end if
    return key;
} // end setKey


// access methods
std::string DataNode::getData() {
    return data;
} // end getData

void DataNode::setData(std::string word) {
    data = word;
    key = setKey();
} // end setData

std::shared_ptr<DataNode> DataNode::getNext() {
    return next;
} // end getNext

void DataNode::setNext(std::shared_ptr<DataNode> node) {
    next = node;
} // end setNext

std::string DataNode::getKey() {
    return key;
} // end getKey
