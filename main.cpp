// main.cpp

#include <fstream>
#include <algorithm> // for std::transform to convert to lowercase

#include "HashTable.h"
#include "TimeInterval.h"

// Function prototypes
void driver();
std::string getInput();
bool isString(std::string); // to make sure that the user input does not contain any numbers
void testLLDataNode();
void testDataNode();
void testHashTable();

int main() {
    TimeInterval timer;
    
    // create an empty hash table
    std::shared_ptr<HashTable> hashtable = std::make_shared<HashTable>();
    
    std::string currentWord;
    std::ifstream inFile;
    inFile.open("Dictionary.txt");
    if (!inFile.is_open()) {
        std::cout << "Unable to open file" << std::endl;
    } else if (inFile.is_open()) {
        while (!inFile.eof()) {
            std::getline(inFile, currentWord); // default delimiter is the new line character
            // create a new data node with the current word
            std::shared_ptr<DataNode> newWord = std::make_shared<DataNode>(currentWord);
            hashtable->insert(newWord);
        } // end while
    } // end else
    
    // get input from the user
    std::string userWord;
    userWord = getInput();
    
    // convert the input to lowercase using std::transform function
    std::transform(userWord.begin(), userWord.end(), userWord.begin(), ::tolower);
    
    // std::cout << "Word to search: " << userWord << std::endl;
    
    // make a new DataNode out of the new word
    std::shared_ptr<DataNode> searchWord = std::make_shared<DataNode>(userWord);
    
    // starting the timer before search
    timer.start();
    
    // search the word in the hash table
    hashtable->search(searchWord);
    
    // stopping the timer after the search is finished
    timer.stop();
    
    // printing the time interval
    std::cout << "Execution Time: " << timer.GetInterval() << " micro-sec" << std::endl;
    
    return 0;
} // end main



std::string getInput() {
    // taking input from the user
    std::cout << "Please enter the word you want to search: " << std::endl;
    std::string response;
    bool keepgoing = true;
    while (keepgoing) {
        std::cin >> response;
        if (response.size() != 0) {
            if (isString(response)) {
                keepgoing = false;
            } else {
                std::cout << "That is not a word. Please enter again: \n";
            } // end if-else
        } // end if
        else  {
            std::cout << "Nothing entered. Please try again." << std::endl;
        }
    } // end while
    return response;
} // end getInput


bool isString(std::string response) {
    bool isString = true;
    for (int i = 0; i < response.size(); i++) {
        if (isdigit(response[i])) {
            return false;
        } // end if
    } // end for
    return isString;
} // end isNumber




/***** TEST METHODS *****/

void testDataNode() {
    std::shared_ptr<DataNode> node = std::make_shared<DataNode>("hello");
    std::cout << "Word: " << node->getData() << std::endl;
    std::cout << "Key: " << node->getKey() << std::endl;
    if (node->getNext() == nullptr) {
        std::cout << "next is null\n";
    } // end if
    std::shared_ptr<DataNode> node2 = std::make_shared<DataNode>();
    node->setNext(node2);
    if (node->getNext() == node2) {
        std::cout << "next is node2\n";
    } // end if
} // end testDataNode


void testLLDataNode() {
    std::shared_ptr<LLDataNode> linkedList = std::make_shared<LLDataNode>();
    if (linkedList->getHead() == nullptr && linkedList->isEmpty()) {
        std::cout << "head is null \n";
    } // end if
    std::shared_ptr<DataNode> node = std::make_shared<DataNode>("hello");
    linkedList->insert(node);
    if (linkedList->getHead() != nullptr && linkedList->isEmpty() == false) {
        std::cout << "head is not null \n";
    } // end if
    std::cout << "Word: " << linkedList->getHead()->getData() << std::endl;
    std::cout << "Key: " << linkedList->getHead()->getKey() << std::endl;
    resultingNodes result;
    result = linkedList->search(node);
    std::cout << "Word exists: " << result.wordExists << std::endl;
    std::cout << "Word found: " << result.word << std::endl;
    if (result.similarWords.size() == 0) {
        std::cout << "No similar words";
    }
} // end testLLDataNode

void testHashTable() {
    HashTable hashtable = HashTable();
    std::cout << "Size of HashTable: " << hashtable.getArray().size() << std::endl;
    for (int i = 0; i < 26; i++) {
        
        if (hashtable.getArray().at(i)->isEmpty()) {
            std::cout << "empty linkedlist \n";
        };
    } // end for
    std::shared_ptr<DataNode> node = std::make_shared<DataNode>("hello");
    std::shared_ptr<DataNode> node2 = std::make_shared<DataNode>("hell");
    std::shared_ptr<DataNode> node3 = std::make_shared<DataNode>("h");
    hashtable.insert(node);
    hashtable.insert(node2);
    hashtable.insert(node3);
    hashtable.search(node3);
} // end testHashTable