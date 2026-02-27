#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <functional>

// Θ(1)
SortedBag::SortedBag(Relation r) {
    this->root = nullptr;
    this->rel = r;
    this->totalSize = 0;
}

//Best Case: Θ(1)
//Average Case: O(log n)
//Worst Case: Θ(n)
void SortedBag::add(TComp e) {
    if (root == nullptr) {
        root = new BSTNode(e);
    } else {
        BSTNode* current = root;

        while (true) {
            if (rel(e, current->info)) {
                if (current->left == nullptr) {
                    current->left = new BSTNode(e);
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == nullptr) {
                    current->right = new BSTNode(e);
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }

    totalSize++;
}

//Best Case: Θ(1)
//Average Case: O(log n)
//Worst Case: Θ(n)
bool SortedBag::remove(TComp e) {
    BSTNode* parent = nullptr;
    BSTNode* current = root;


    while (current != nullptr && current->info != e) {
        parent = current;
        if (rel(e, current->info)) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == nullptr) {
        return false;
    }


    if (current->left == nullptr || current->right == nullptr) {
        BSTNode* child = nullptr;
        if (current->left != nullptr) {
            child = current->left;
        } else {
            child = current->right;
        }

        if (parent == nullptr) {
            root = child;
        } else if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }

        delete current;
    }

    else {
        BSTNode* succParent = current;
        BSTNode* successor = current->right;

        while (successor->left != nullptr) {
            succParent = successor;
            successor = successor->left;
        }

        current->info = successor->info;

        if (succParent->left == successor) {
            succParent->left = successor->right;
        } else {
            succParent->right = successor->right;
        }

        delete successor;
    }

    totalSize--;
    return true;
}

// Best case: Θ(1)
// Average Case: Θ(log n)
// Worst case: Θ(n)
bool SortedBag::search(TComp elem) const {
    BSTNode* current = root;
    while (current != nullptr) {
        if (current->info == elem) return true;
        if (rel(elem, current->info)) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

// Best case: Θ(n)
// Average Case: Θ(n)
// Worst case: Θ(n)
int SortedBag::nrOccurrences(TComp elem) const {
    std::function<int(BSTNode*)> countRec = [&](BSTNode* node) -> int {
        if (node == nullptr) return 0;

        int count;
        if (node->info == elem) {
            count = 1;
        } else {
            count = 0;
        }

        return count + countRec(node->left) + countRec(node->right);
    };

    return countRec(root);
}

// Best case: Θ(1)
// Average Case: Θ(1)
// Worst case: Θ(1)
int SortedBag::size() const {
    return totalSize;
}

// Best case: Θ(1)
// Average Case: Θ(1)
// Worst case: Θ(1)
bool SortedBag::isEmpty() const {
    return totalSize == 0;
}

//Best Case: Θ(n)
//Average Case: O(n)
//Worst Case: Θ(n)
SortedBag::~SortedBag() {
    while (root != nullptr) {
        BSTNode* current = root;
        BSTNode* parent = nullptr;

        while (current->left != nullptr || current->right != nullptr) {
            parent = current;

            if (current->left != nullptr) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        if (current == root) {
            delete root;
            root = nullptr;
        }
        else {
            if (parent->left == current) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
            delete current;
        }
    }
}
// Best case: Θ(1)
// Average Case: Θ(1)
// Worst case: Θ(1)
SortedBagIterator SortedBag::iterator() const {
    return SortedBagIterator(*this);
}

// Best case: Θ(1)
// Average Case: Θ(n)
// Worst case: Θ(n)
bool SortedBag::operator==(const SortedBag &other) const {
    if (this->size() != other.size()) {
        return false;
    }

    SortedBagIterator it1 = this->iterator();
    SortedBagIterator it2 = other.iterator();

    while (it1.valid() && it2.valid()) {
        if (it1.getCurrent() != it2.getCurrent()) {
            return false;
        }
        it1.next();
        it2.next();
    }

    if (!it1.valid() && !it2.valid()) {
        return true;
    }
}



