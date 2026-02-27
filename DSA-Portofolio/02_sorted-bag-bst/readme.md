# SortedBag (BST with Duplicates as Multiple Nodes)

Implementation of a SortedBag (multiset) ADT using a Binary Search Tree representation.
Duplicate elements are stored as separate nodes in the BST.

## Representation

- Binary Search Tree (BST)
- Each node stores:
  - `info` (value)
  - `left`, `right` pointers
- Ordering is defined by a user-provided `Relation` function.

## Key Operations

- `add(e)` – inserts an element according to the relation
- `remove(e)` – removes one occurrence of an element
- `search(e)` – checks if an element exists
- `nrOccurrences(e)` – counts occurrences of an element by traversing the tree
- Custom iterator – in-order traversal using an explicit dynamic stack (no STL containers)

## Complexity

Let `n` be the number of elements.

- `add(e)`  
  Average: O(log n)  
  Worst: O(n)

- `remove(e)`  
  Average: O(log n)  
  Worst: O(n)

- `search(e)`  
  Average: O(log n)  
  Worst: O(n)

- `nrOccurrences(e)`  
  O(n)

## Technical Highlights

- Manual dynamic memory management
- BST deletion cases handled (0/1 child and 2 children via in-order successor)
- Iterator implemented with a resizable stack allocated dynamically

## Learning Focus

- BST-based ADT design
- Handling duplicates in a BST
- Iterator design (in-order traversal)
- Complexity analysis
