// DataNode.h

#include <cstdlib>
#include <string>
#include <memory>

#ifndef DATANODE_H
#define DATANODE_H

class DataNode {
    
    protected:
        std::string data;
        std::shared_ptr<DataNode> next;
    
    public: 
        DataNode();
        DataNode(std::string word);
        
        // getters and setters
        std::string getData();
        void setData(std::string word);
        std::shared_ptr<DataNode> getNext();
        void setNext(std::shared_ptr<DataNode> node);
    
}; // end class declaration

#endif /* DATANODE_H */

