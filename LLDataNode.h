// LLDataNode.h

#include <vector>
#include "DataNode.h"

#ifndef LLDATANODE_H
#define LLDATANODE_H

// a struct to simplify keeping track of all the valid words found in the process
struct resultingNodes {
    std::vector<std::string> similarWords;
    std::string word;
    bool wordExists;
};

class LLDataNode {
    
    protected:
        std::shared_ptr<DataNode> head;

    public:
        LLDataNode();
        void insert(std::shared_ptr<DataNode> node);
        bool isEmpty();
        resultingNodes search(std::shared_ptr<DataNode> word);
        
        // access methods
        std::shared_ptr<DataNode> getHead();
        void setHead(std::shared_ptr<DataNode> node);
}; // end class declaration

#endif /* LLDATANODE_H */

