
#include "LLDataNode.h"

// LLDataNode.cpp

LLDataNode::LLDataNode() {
//    head = std::make_shared<DataNode>(); // calling the constructor
//    head->setData("");
//    head->setNext(nullptr);
    head = nullptr;
} // end constructor

void LLDataNode::insert(std::shared_ptr<DataNode> node) {
    std::shared_ptr<DataNode> currentHead = std::make_shared<DataNode>();
    *currentHead = *head;
    *head = *node;
    head->setNext(currentHead);
} // end insert

bool LLDataNode::isEmpty() {
    if (head == nullptr) {
        return true;
    } else {
        return false;
    }
} // end isEmpty


// access methods
std::shared_ptr<DataNode> LLDataNode::getHead() {
    return head;
} // end getHead

void LLDataNode::setHead(std::shared_ptr<DataNode> node) {
    head = node;
} // end setHead