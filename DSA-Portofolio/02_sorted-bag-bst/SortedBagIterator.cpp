#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	stackCapacity = 100;
	stack = new BSTNode*[stackCapacity];
	stackTop = -1;
	first();
}


void SortedBagIterator::initStack() {
	stackTop = -1;
}

void SortedBagIterator::push(BSTNode* node) {
	if (stackTop + 1 == stackCapacity) {
		int newCap = stackCapacity * 2;
		BSTNode** newStack = new BSTNode*[newCap];
		for (int i = 0; i < stackCapacity; ++i) newStack[i] = stack[i];
		delete[] stack;
		stack = newStack;
		stackCapacity = newCap;
	}
	stack[++stackTop] = node;
}

BSTNode* SortedBagIterator::pop() {
	if (stackTop == -1) return nullptr;
	return stack[stackTop--];
}

bool SortedBagIterator::isEmptyStack() const {
	return stackTop == -1;
}

void SortedBagIterator::first() {
	initStack();
	BSTNode* current = bag.root;
	while (current != nullptr) {
		push(current);
		current = current->left;
	}
	currentNode = pop();
}

void SortedBagIterator::next() {
	if (!valid()) throw std::exception();
	if (currentNode->right != nullptr) {
		BSTNode* temp = currentNode->right;
		while (temp != nullptr) {
			push(temp);
			temp = temp->left;
		}
	}
	currentNode = pop();
}

bool SortedBagIterator::valid() {
	return currentNode != nullptr;
}

TComp SortedBagIterator::getCurrent() {
	if (!valid()) throw std::exception();
	return currentNode->info;
}

