#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
using namespace std;
#include <exception>

SortedIteratedList::SortedIteratedList(Relation r) {  //θ(1)
	this->r = r;
    this->length = 0;
    this->head = nullptr;
}

int SortedIteratedList::size() const { //θ(1)
	return this->length;
}

bool SortedIteratedList::isEmpty() const {  //θ(1)
	return (this->length == 0);
}

ListIterator SortedIteratedList::first() const {   //θ(1)
	return ListIterator(*this);
}

TComp SortedIteratedList::getElement(ListIterator poz) const {   //θ(1)
	if (!poz.valid()) {
		throw std::exception();
	}

	return poz.getCurrent();
}

TComp SortedIteratedList::remove(ListIterator& poz) {
	if (!poz.valid()) {
		throw std::exception();
	}

	TComp removedValue;

	// Case 1: Se elimina primul element(head)  //θ(1)
	if (this->head == poz.current) {
		Node* toDelete = this->head;
		removedValue = this->head->info;

		this->head = this->head->nxt;
		delete toDelete;
		this->length--;
		poz.current = this->head;
		return removedValue;
	}

	// Case 2: Se elimina element care nu e head  // O(n)
	Node* prev = this->head;
	while (prev->nxt != poz.current && prev->nxt != nullptr) {
		prev = prev->nxt;
	}
	if (prev->nxt == nullptr) {
		throw std::exception();
	}
	Node* toDelete = prev->nxt;
	removedValue = toDelete->info;
	prev->nxt = toDelete->nxt;
	delete toDelete;
	this->length--;
	poz.current = prev->nxt;
	return removedValue;
}

ListIterator SortedIteratedList::search(TComp e) const{ //Best Case: θ(1) , Worst Case: O(n)
	ListIterator it = first();
	while (it.valid() && it.getCurrent() != e) {
		it.next();
	}
	return it;
}

void SortedIteratedList::add(TComp e) {
	Node* newNode = new Node;
	newNode->info = e;
	newNode->nxt = nullptr;

	// Case 1: daca lista ii goala sau trb inserat la inceput   θ(1)
	if (this->head == nullptr || r(e, this->head->info)) {
		newNode->nxt = this->head;
		this->head = newNode;
	} else {
		// Case 2: Cautam in lista unde trebuie s afie inserat elementul Best Case:  θ(1), Worst Case: O(n)
		Node* current = this->head;
		while (current->nxt != nullptr && !r(e, current->nxt->info)) {
			current = current->nxt;
		}
		newNode->nxt = current->nxt;
		current->nxt = newNode;
	}
	this->length++;
}


SortedIteratedList::~SortedIteratedList() {  //O(n)
	Node* current = this->head;
	while (current != nullptr) {
		Node* next = current->nxt;
		delete current;
		current = next;
	}
}
