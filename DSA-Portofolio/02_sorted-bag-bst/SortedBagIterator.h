#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;

	BSTNode** stack;
	int stackCapacity;
	int stackTop;
	BSTNode* currentNode;

	SortedBagIterator(const SortedBag& b);
	void push(BSTNode* node);
	BSTNode* pop();
	bool isEmptyStack() const;
	void initStack();


public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
};

