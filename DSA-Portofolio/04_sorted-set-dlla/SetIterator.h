#pragma once
#include "Set.h"
#include <exception>

using namespace std;

class SetIterator
{
	//DO NOT CHANGE THIS PART
	friend class Set;
private:
	//DO NOT CHANGE THIS PART
	const Set& set;
	SetIterator(const Set& s);

	int currentElement;

public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};


