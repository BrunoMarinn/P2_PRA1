CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

BIN = bin

all: $(BIN)/testTableEntry $(BIN)/testHashTable $(BIN)/testBSTree $(BIN)/testBSTreeDict

$(BIN)/testTableEntry: Dict.h TableEntry.h testTableEntry.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -o $(BIN)/testTableEntry testTableEntry.cpp

$(BIN)/testHashTable: Dict.h TableEntry.h List.h Node.h ListLinked.h HashTable.h testHashTable.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -o $(BIN)/testHashTable testHashTable.cpp

$(BIN)/testBSTree: BSTree.h BSNode.h testBSTree.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -o $(BIN)/testBSTree testBSTree.cpp

$(BIN)/testBSTreeDict: Dict.h BSTreeDict.h BSTree.h BSNode.h TableEntry.h testBSTreeDict.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -o $(BIN)/testBSTreeDict testBSTreeDict.cpp

clean:
	rm -rf $(BIN) *.o *.gch

