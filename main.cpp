// main.cpp

#include <fstream>
#include <algorithm> // for std::transform to convert to lowercase

#include "HashTable.h"

// Function prototypes
std::string getInput(); // to get user input
bool isString(std::string); // to make sure that the user input does not contain any numbers
void printHashTable(std::shared_ptr<HashTable> hashtable); // to print the hash table


int main() {
    // create an empty hash table
    std::shared_ptr<HashTable> hashtable = std::make_shared<HashTable>();
    
    // reading in the file and storing all the words in the hash table
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
            // insert all the words as lowercase using casting to check whether a word contains an uppercase beginning letter
            if ((int) currentWord[0] < 97) {
                std::transform(currentWord.begin(), currentWord.end(), currentWord.begin(), ::tolower);
                newWord->setData(currentWord);
            } // end if
            hashtable->insert(newWord);
        } // end while
    } // end else
    
    // print the hash table
    std::cout << "Printing the Hash Table: \n";
    printHashTable(hashtable);
    
    // get input from the user
    std::string userWord;
    userWord = getInput();
    
    // convert the input to lowercase using std::transform function
    std::transform(userWord.begin(), userWord.end(), userWord.begin(), ::tolower);
    
    // make a new DataNode out of the new word
    std::shared_ptr<DataNode> searchWord = std::make_shared<DataNode>(userWord);
    
    // search the word in the hash table
    hashtable->search(searchWord);

    return 0;
} // end main



std::string getInput() {
    // taking input from the user
    std::cout << "\n\nPlease enter the word you want to search: " << std::endl;
    std::string response;
    bool keepgoing = true;
    while (keepgoing) {
        std::cin >> response;
        if (response.length() != 0) {
            if (isString(response)) {
                keepgoing = false;
            } else {
                std::cout << "That is not a word. Please enter again: \n";
            } // end if-else
        } // end if
        else if (response == " " || response == "") {
            std::cout << "Nothing entered. Please try again." << std::endl;
        } // end else
    } // end while
    return response;
} // end getInput


bool isString(std::string response) {
    bool isString = true;
    for (unsigned int i = 0; i < response.length(); i++) {
        if (isdigit(response[i])) {
            return false;
        } // end if
    } // end for
    return isString;
} // end isNumber


void printHashTable(std::shared_ptr<HashTable> hashtable) {
    for (int i = 0; i < 26; i++) {
        std::cout << "Index " << i << ":  ";
        hashtable->getArray().at(i)->print();
        std::cout << std::endl;
    } // end for
} // end printHashTable