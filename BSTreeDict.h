#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
	    BSTree<TableEntry<V>>* tree;

    public:
	    BSTreeDict(){
		    tree = new BSTree<TableEntry<V>>;
	    }

	    ~BSTreeDict(){
		delete tree;
	    }

	    friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
		    out<<*(bs.tree);
		    return out;
	    }

	    V operator[](std::string key){
		    return search(key);
	    }

	    void insert(std::string key, V value)override{
		    TableEntry<V> aux(key, value);
		    tree->insert(aux);
	    }

	    V search(std::string key) override{
		    TableEntry<V> aux(key);
                    return tree->search(aux).value;
	    }

	    V remove(std::string key) override{
		    TableEntry<V> aux(key);
		    V sol = tree->search(aux).value;
		    tree->remove(aux);
		    return sol;
	    }

	    int entries() override{
                    return tree->size();
            }
			
        
};

#endif

