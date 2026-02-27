#include "SetIterator.h"
#include "Set.h"

// Best case - ϴ(1)
// Avg. case - ϴ(1)
// Worst case - ϴ(1)
SetIterator::SetIterator(const Set& m) : set(m)
{
	this->currentElement = set.head;
}

// Best case - ϴ(1)
// Avg. case - ϴ(1)
// Worst case - ϴ(1)
void SetIterator::first() {
	this->currentElement = set.head;
}

// Best case - ϴ(1)
// Avg. case - ϴ(1)
// Worst case - ϴ(1)
void SetIterator::next() {
	if (!valid()) {
		throw exception();
	}

	currentElement = set.next[currentElement];
}

// Best case - ϴ(1)
// Avg. case - ϴ(1)
// Worst case - ϴ(1)
TElem SetIterator::getCurrent()
{
	if (!valid()) {
		throw exception();
	}

	return set.elems[currentElement];
}

// Best case - ϴ(1)
// Avg. case - ϴ(1)
// Worst case - ϴ(1)
bool SetIterator::valid() const {
	if (currentElement != -1) {
		return true;
	}

	return false;
}



