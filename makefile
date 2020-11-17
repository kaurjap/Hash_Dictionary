runHash: DataNode.o LLDataNode.o HashTable.o main.o
	g++ -std=c++11 -g -Wall DataNode.o LLDataNode.o HashTable.o main.o -o runHash

main.o: DataNode.h LLDataNode.h HashTable.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

DataNode.o: DataNode.h DataNode.cpp
	g++ -std=c++11 -g -Wall -c DataNode.cpp

LLDataNode.o: DataNode.h LLDataNode.h LLDataNode.cpp
	g++ -std=c++11 -g -Wall -c LLDataNode.cpp

HashTable.o: DataNode.h LLDataNode.h HashTable.h HashTable.cpp
	g++ -std=c++11 -g -Wall -c HashTable.cpp

run: runHash
	./runHash

debug: runHash
	gdb -tui ./runHash

clean:
	rm *.o
	rm runHash

valgrind: runHash
	valgrind ./runHash
