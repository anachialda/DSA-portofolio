#pragma once
#include "SortedIteratedList.h"

//DO NOT CHANGE THIS PART
class ListIterator {
	friend class SortedIteratedList;
private:
    const SortedIteratedList& list;

    SortedIteratedList::Node* current;

	ListIterator(const SortedIteratedList& list);


public:
	void first();
	void next();
	bool valid() const;
    TComp getCurrent() const;
    void insert(TComp e);
};


