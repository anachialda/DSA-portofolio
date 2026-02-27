#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>

using namespace std;

ListIterator::ListIterator(const SortedIteratedList& list) : list(list){   //θ(1)
	this->current = list.head;
}

void ListIterator::first(){  //θ(1)
	this->current = list.head;
}

void ListIterator::next(){  //θ(1)
	if (!valid()) {
		throw std::exception();
	}
	current = current->nxt;
}

bool ListIterator::valid() const{   //θ(1)
    return current != nullptr;
}

TComp ListIterator::getCurrent() const{  //θ(1)
	if (!valid()) {
		throw std::exception();
	}
	return current->info;
}

void ListIterator::insert(TComp e){  // Best Case: θ(1), Worst Case: O(n)
	SortedIteratedList &List = const_cast<SortedIteratedList&>(list);

	SortedIteratedList::Node* newNode = new SortedIteratedList::Node;
	newNode->info = e;
	newNode->nxt = current;

    if (current == list.head) {
      List.head = newNode;
    }
    else {
    	SortedIteratedList::Node* prev = List.head;
    	while (prev != nullptr && prev->nxt != current) {
    		prev = prev->nxt;
    	}
    	if (prev == nullptr) {
    		throw std::exception();
    	}

    	prev->nxt = newNode;
    }
	List.length++;
	current = newNode;
}






