// HashTable.h

#include <vector>
#include "LLDataNode.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {
    protected:
        std::vector<LLDataNode> array;
        
    public:
        HashTable();
        int hashFunction(std::string key);
        bool search(std::string key, std::string value);
        void populateHashTable(std::string filename);
        
        // access method
        std::vector<LLDataNode> getArray();
}; // end class declaration

#endif /* HASHTABLE_H */

