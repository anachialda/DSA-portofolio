# Sparse Matrix (Compressed Column Storage – CCS)

Implementation of an ADT Matrix stored as a sparse matrix using the Compressed Column Storage (CCS) format.

## Representation

The matrix is stored using three dynamic arrays:

- `values[]` – stores all non-zero elements
- `rows[]` – row index for each stored element
- `columns[]` – column pointer array (size = nrColumns + 1)

For column j:
- non-zero elements are stored in the interval:
  values[columns[j] ... columns[j+1] - 1]

## Key Operations

- `element(i, j)` – retrieves value at position (i, j)
- `modify(i, j, value)` – inserts, updates or deletes a value
- Dynamic resizing when capacity is exceeded
- Manual shifting of elements for insert/delete
- Custom iterator over stored elements

## Complexity Overview

- `element(i, j)`  
  Best: O(1)  
  Worst: O(k) (k = non-zero elements in column)

- `modify(i, j, value)`  
  Best: O(1)  
  Worst: O(n) (due to shifting and column updates)

## Technical Highlights

- Manual dynamic memory management
- No STL containers
- Explicit time complexity analysis
- Column-based sparse storage optimization

## Learning Focus

- Sparse matrix representations
- Memory-efficient storage
- Low-level array manipulation
- Algorithmic complexity analysis
