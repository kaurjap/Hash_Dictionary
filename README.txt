Instructions for compilation

  TASKS                                                     	      COMMANDS
  To compile, execute:                                      	      make
  To compile and run, execute:                              	      make run
  To clean the current compilation and object files, execute:         make clean 




ALGORITHM:

GOAL: to built a word suggestion program utilizing hashing to store words from the "Dictionary.txt" file into a hash table for easy look up. The hash table is just an array of linked lists in this program.
INPUT: the "Dictionary.txt" file, the user's input for what word to look up
OUTPUT: boolean for whether the word exists or not, similar words suggested

STEPS:

1. I build a manual hash table. To do so, I create three classes to organize the overall program. The DataNode class represents each word in the Dictionary.txt file. When the file is read, each of the words is stored as an object of type DataNode, which are then hashed to be stored in a vector of linked lists in the HashTable class. The LLDataNode class represents each linked list of data nodes that is stored in the vector that is referred to as the hash table for this program. 


2. The first letter of a word is used as a key to hash words to their spots in the hash table. Essentially, the hash function that I chose is chosen so that it hashes all of the words that start with the same first letter into the same spot, in the same linked list (also referred to as the same bucket) in the hash table. The hash function used is the following:
	k = first character of the word being hased (char)
	hashCode = refers to the ending result

	hashCode = ((int) k + 7) % 26

	the use of (int) before the character k is referred to as type casting, where a character is being converted to type int, which, in this case, results in its ascii value
	The result of the ascii value + 7 is being divided by 26 to get its remainder so that the resulting hashCode index is in the range 26 which is the size of the vector where all the words are stored as linked lists
	Using this hash function, it is made sure that the only collisions that happen are if the words start with the same first letter. This is shown as output in my program when I print the hash table to display what the program is doing.
	All of this is done by the hashFunction() that is part of the HashTable class in code.


3. Searching is performed by the function search defined in the HashTable class. Since the program is supposed to suggest words that begin with the same first two letters, the DataNode class contains a variable to store that. Hence, when the search function is called, it takes in the user input as the word to search for (converted into lowercase), finds the hashCode index of where it is stored in the hashTable, and then traverses through the linked list in that spot to search for the exact element. While it traverses, it also stores all the other words that start with the same two letters. Once this seach is executed, this result is printed. 


4. The timer for the execution time that it takes to search is started right before the searching algorithm is started, and it stops right after the program is done searching through the specified linked list to look for the word, returning a struct that contains the list of all the similar words and a boolean to express whether the exact word exists in the dictionary or not.

5. In the end, the output from the search method is printed as results on the console.



FEATURES OF THE PROGRAM:

1. The program is case insensitive. The word "WHO" is regarded to be the same as "who" to search in the dictionary.
2. If the word exists in the file, the program outputs "True" and lists other similar words that begin with the same first two letters that have been found, if any.
3. If the word does not exist in the file, the program outputs "False", but still suggests other similar words that begin with the same first two letters that have been found, again, if any.
4. If the word entered is only letter long, for example "I", it returns "True" if the word exists. However, there are no similar words that exist that show up because the suggested words are based on the first two letters.


WHAT THE OUTPUT SAYS:

The first part of what I output on the screen is the hash table itself. This is just to display how the hash function that I used is working to store the words. 
The second part is where the program takes input from the user and outputs whether it exists in the file or not as mentioned above.


