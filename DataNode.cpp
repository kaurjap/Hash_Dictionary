// DataNode.cpp

#include "DataNode.h"

DataNode::DataNode() {
    data = "";
    next = nullptr;
} // end constructor

DataNode::DataNode(std::string word) {
    data = word;
    next = nullptr;
} // end parameterized constructor


// access methods
std::string DataNode::getData() {
    return data;
} // end getData

void DataNode::setData(std::string word) {
    data = word;
} // end setData

std::shared_ptr<DataNode> DataNode::getNext() {
    return next;
} // end getNext

void DataNode::setNext(std::shared_ptr<DataNode> node) {
    next = node;
} // end setNext