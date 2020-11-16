// main.cpp

#include <fstream>
#include <algorithm> // for std::transform to convert to lowercase

#include "HashTable.h"
#include "TimeInterval.h"

// Function prototypes
void driver();
std::string getInput();
bool isString(std::string); // to make sure that the user input does not contain any numbers


int main() {
    
    // driver();
    // TEST THE METHODS
    
    
    
} // end main


void driver() {
    
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
    
    std::cout << "Word to search: " << userWord << std::endl;
    
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
    
} // end driver


std::string getInput() {
    // taking input from the user
    std::cout << "Please enter the word you want to search" << std::endl;
    std::string response;
    bool keepgoing = true;
    while (keepgoing) {
        std::cin >> response;
        if (isString(response)) {
            keepgoing = false;
        } else {
            std::cout << "That is not a word. Please enter again: \n";
        } // end if-else
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