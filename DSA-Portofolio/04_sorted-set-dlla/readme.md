# Set (Dynamic Doubly Linked List on Array – DLLA)

Implementation of a Set ADT using an array-based linked list (DLLA).

## Representation

The set is implemented using:

- `elems[]` – stores the values
- `next[]` – simulates linked list connections
- `head` – index of the first element
- `firstEmpty` – index of first free slot
- `capacity` – current array size

A free list is maintained for efficient reuse of deleted positions.

## Key Operations

- `add(e)` – inserts element if not already present
- `remove(e)` – removes element if it exists
- `search(e)` – checks membership
- `iterator()` – returns iterator over elements

## Dynamic Resizing

- Capacity doubles when full
- Capacity shrinks when size reaches 1/4 of capacity

## Complexity

- `search(e)`  
  Best: O(1)  
  Worst: O(n)

- `add(e)`  
  Best: O(1)  
  Worst: O(n)

- `remove(e)`  
  Best: O(1)  
  Worst: O(n)

- `size()`  
  O(n)

## Technical Highlights

- Manual memory management
- Free list implementation
- Array-based linked structure (DLLA)
- Dynamic resizing (expand & shrink)

## Learning Focus

- Simulating linked structures using arrays
- Memory reuse techniques
- Amortized resizing strategies
