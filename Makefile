CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

BIN = bin

all: $(BIN)/testTableEntry $(BIN)/testHashTable $(BIN)/testBSTree $(BIN)/testBSTreeDict

$(BIN)/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -o $(BIN)/testTableEntry testTableEntry.cpp

$(BIN)/testHashTable: testHashTable.cpp HashTable.h Dict.h TableEntry.h List.h Node.h ListLinked.h
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -o $(BIN)/testHashTable testHashTable.cpp

$(BIN)/testBSTree: testBSTree.cpp BSTree.h BSNode.h
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -o $(BIN)/testBSTree testBSTree.cpp

$(BIN)/testBSTreeDict: testBSTreeDict.cpp BSTreeDict.h BSTree.h BSNode.h TableEntry.h Dict.h
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -o $(BIN)/testBSTreeDict testBSTreeDict.cpp

clean:
	rm -rf $(BIN) *.o *.gch

