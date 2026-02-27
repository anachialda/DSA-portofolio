# SortedIteratedList (Singly Linked List)

Implementation of a sorted list using a singly linked list representation.

The ordering of elements is defined by a user-provided relation function.

## Representation

- Singly linked list
- Each node stores:
  - `info` (value)
  - `nxt` (pointer to next node)
- The list maintains sorted order according to a relation `r`

## Key Operations

- `add(e)` – inserts element while preserving sorted order
- `remove(iterator)` – removes element at given iterator position
- `search(e)` – returns iterator to first occurrence
- Custom iterator with:
  - `first()`
  - `next()`
  - `valid()`
  - `getCurrent()`
  - `insert(e)` at iterator position

## Complexity

- `add(e)`  
  Best: O(1)  
  Worst: O(n)

- `remove(iterator)`  
  Best: O(1) (removing head)  
  Worst: O(n)

- `search(e)`  
  Best: O(1)  
  Worst: O(n)

- Destructor  
  O(n)

## Technical Highlights

- Manual dynamic memory management
- Sorted insertion without auxiliary structures
- Custom iterator implementation
- Separation of ordering logic via function pointer (Relation)

## Learning Focus

- Linked list manipulation
- Pointer-based data structures
- Iterator abstraction
- Complexity analysis
