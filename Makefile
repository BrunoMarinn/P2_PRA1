$(BIN)/testBSTree: BSTree.h BSNode.h testBSTree.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -o $(BIN)/testBSTree testBSTree.cpp

$(BIN)/testBSTreeDict: Dict.h BSTreeDict.h BSNode.h TableEntry.h testBSTreeDict.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -o $(BIN)/testBSTreeDict testBSTreeDict.cpp

