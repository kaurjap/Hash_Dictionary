// LLDataNode.cpp


#include "LLDataNode.h"


LLDataNode::LLDataNode() {
//    head = std::make_shared<DataNode>(); // calling the constructor
//    head->setData("");
//    head->setNext(nullptr);
    head = nullptr;
} // end constructor


void LLDataNode::insert(std::shared_ptr<DataNode> node) {
    std::shared_ptr<DataNode> currentHead = std::make_shared<DataNode>();
    currentHead = head;
    head = node;
    head->setNext(currentHead);
} // end insert


bool LLDataNode::isEmpty() {
    if (head == nullptr) {
        return true;
    } else {
        return false;
    }
} // end isEmpty


resultingNodes LLDataNode::search(std::shared_ptr<DataNode> word) {
    resultingNodes result; // struct to store the boolean value and the words to store in a list of similar words
    result.word = "";
    result.wordExists = false;
    
    // if the list is empty
    if (head == nullptr) {
        std::cout << "The word doesn't exist. No similar words exist either" << std::endl;
        result.wordExists = false;
    } else {
        // start traversing from the head of the linked list and compare each word
        std::shared_ptr<DataNode> currentNode = head;
        while (currentNode != nullptr) {
            // compare the key and value of this element with the word being searched for
            if (currentNode->getData() == word->getData() && currentNode->getKey() == word->getKey()) {
                // the word exists
                // print the word
                //std::cout << currentHead->getData() << std::endl;
                result.word = currentNode->getData();
                result.wordExists = true;
            } // end if
            
            // if only the first two letters are the same
            else if (currentNode->getData() != word->getData() && currentNode->getKey() == word->getKey()) {
                // std::cout << currentHead->getData() << std::endl;
                // add the word to the similar words list
                result.similarWords.push_back(currentNode->getData());
            } // end else if
            
            /*
            else if (word->getData().size() == 1) {
                std::cout << "The first 2 letters are needed to find other similar words.\n";
            } // end else if
            */
            
            currentNode = currentNode->getNext();
        } // end while
    } // end else
    return result;
} // end search


// access methods
std::shared_ptr<DataNode> LLDataNode::getHead() {
    return head;
} // end getHead


void LLDataNode::setHead(std::shared_ptr<DataNode> node) {
    head = node;
} // end setHead

void LLDataNode::print() {
    std::shared_ptr<DataNode> currentNode = std::make_shared<DataNode>();
    currentNode = head;
    while (currentNode != nullptr) {
        std::cout << currentNode->getData() << ", ";
        currentNode = currentNode->getNext();
    } // end while
} // end print