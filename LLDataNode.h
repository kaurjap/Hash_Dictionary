// LLDataNode.h

#include "DataNode.h"

#ifndef LLDATANODE_H
#define LLDATANODE_H

class LLDataNode {
    
    protected:
        std::shared_ptr<DataNode> head;

    public:
        LLDataNode();
        void insert(std::shared_ptr<DataNode> node);
        bool isEmpty();
        
        // access methods
        std::shared_ptr<DataNode> getHead();
        void setHead(std::shared_ptr<DataNode> node);
}; // end class declaration

#endif /* LLDATANODE_H */

