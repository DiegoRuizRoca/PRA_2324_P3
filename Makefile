bin/testBSTreeDict: Dict.h BSNode.h TableEntry.h BSTreeDict.h testBSTreeDict.cpp
	mkdir -p bin
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp

clean:
	rm -rf *.o *.gch bin
