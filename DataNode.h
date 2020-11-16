// DataNode.h

#include <cstdlib>
#include <iostream>
#include <string>
#include <memory>

#ifndef DATANODE_H
#define DATANODE_H


class DataNode {
    
    protected:
        std::string key; // the first two letters of the string
        std::string data;
        std::shared_ptr<DataNode> next;
    
    public: 
        DataNode();
        DataNode(std::string word);
        std::string setKey(); // gets the first two letters of the given word
        
        // getters and setters
        std::string getData();
        void setData(std::string word);
        std::shared_ptr<DataNode> getNext();
        void setNext(std::shared_ptr<DataNode> node);
        std::string getKey();
        
}; // end class declaration

#endif /* DATANODE_H */

