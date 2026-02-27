#include "Set.h"
#include "SetIterator.h"

// Best case - ϴ(capacity)
// Avg. case - ϴ(capacity)
// Worst case - ϴ(capacity)
Set::Set() {
    this->capacity = 5;
	this->elems = new TElem[this->capacity];
	this->next = new int[this->capacity];
	this->head = -1;
	for (int i = 0; i < this->capacity - 1; i++) {
		this->next[i] = i + 1;
	}

	this->next[this->capacity-1] = -1;
	this->firstEmpty = 0;
}

// Best case - ϴ(1)
// Avg. case - ϴ(n)
// Worst case - O(n)
bool Set::add(TElem elem) {
	if (search(elem)) {
		return false;
	}

	if (firstEmpty == -1) {
		int newCapacity = this->capacity * 2;
		TElem* newElems = new TElem[newCapacity];
		int* newNext = new int[newCapacity];

		for (int i = 0; i < this->capacity; i++) {
			newElems[i] = this->elems[i];
			newNext[i] = this->next[i];
		}

		for (int i = this->capacity; i < newCapacity - 1; i++) {
			newNext[i] = i + 1;
		}
		newNext[newCapacity - 1] = -1;

		firstEmpty = this->capacity;
		delete[] this->elems;
		delete[] this->next;

		this->elems = newElems;
		this->next = newNext;
		this->capacity = newCapacity;
	}

	int newFirstEmpty = firstEmpty;
	firstEmpty = next[firstEmpty];
	elems[newFirstEmpty] = elem;
	next[newFirstEmpty] = head;
	head = newFirstEmpty;

	return true;
}

// Best case - ϴ(1)
// Avg. case - ϴ(n)
// Worst case - O(n)
bool Set::remove(TElem elem) {
	int current = head;
	int prev = -1;
	int count = size();

	while (current != -1 && elems[current] != elem) {
		prev = current;
		current = next[current];
	}

	if (current == -1) {
		return false;
	}

	if (prev == -1) {
		head = next[head];
	} else {
		next[prev] = next[current];
	}

	next[current] = firstEmpty;
	firstEmpty = current;
	count--;

	if (count > 0 && count == capacity / 4) {
		int newCapacity = capacity / 2;
		TElem* newElems = new TElem[newCapacity];
		int* newNext = new int[newCapacity];

		int newFirstEmpty = 0;
		int newIndex = 0;
		int oldIndex = head;
		int prevNewIndex = -1;

		while (oldIndex != -1 && newIndex < newCapacity) {
			newElems[newIndex] = elems[oldIndex];
			if (prevNewIndex != -1) {
				newNext[prevNewIndex] = newIndex;
			}

			prevNewIndex = newIndex;
			oldIndex = next[oldIndex];
			newIndex++;
		}

		if (prevNewIndex != -1) {
			newNext[prevNewIndex] = -1;
		}

		for (int i = newIndex; i < newCapacity - 1; ++i) {
			newNext[i] = i + 1;
		}
		newNext[newCapacity - 1] = -1;

		delete[] elems;
		delete[] next;

		elems = newElems;
		next = newNext;
		capacity = newCapacity;
		head = 0;
		firstEmpty = newIndex < newCapacity ? newIndex : -1;
	}

	return true;
}

// Best case - ϴ(1)
// Avg. case - ϴ(n)
// Worst case - O(n)
bool Set::search(TElem elem) const {
	int current = head;

	while (current != -1) {
		if (elems[current] == elem) {
			return true;
		}
		current = next[current];
	}

	return false;
}

// Best case - ϴ(n)
// Avg. case - ϴ(n)
// Worst case - ϴ(n)
int Set::size() const {
	int count = 0;
	int current = head;

	while (current != -1) {
		count++;
		current = next[current];
	}

	return count;
}

// Best case - ϴ(1)
// Avg. case - ϴ(1)
// Worst case - ϴ(1)
bool Set::isEmpty() const {
	if (head == -1) {
		return true;
	}

	return false;
}

// Best case - ϴ(1)
// Avg. case - ϴ(1)
// Worst case - ϴ(1)
Set::~Set() {
	delete[] elems;
	delete[] next;
}

// Best case - ϴ(1)
// Avg. case - ϴ(1)
// Worst case - ϴ(1)
SetIterator Set::iterator() const {
	return SetIterator(*this);
}

