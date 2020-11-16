// HashTable.h

#include <vector>
#include "LLDataNode.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {
    protected:
        // vector to store all the linked lists into their hashed positions
        std::vector< std::shared_ptr<LLDataNode> > array; // vector of size 26
        
    public:
        HashTable();
        int hashFunction(std::string key);
        void insert(std::shared_ptr<DataNode> node);
        void search(std::shared_ptr<DataNode> word);
        // void populateHashTable(std::string filename);
        
        // access method
        std::vector<LLDataNode> getArray();
}; // end class declaration

#endif /* HASHTABLE_H */

