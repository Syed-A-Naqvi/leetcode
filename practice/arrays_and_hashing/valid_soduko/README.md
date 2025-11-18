# Valid Sudoku

## Problem Description
Given a `9x9` Sudoku board `board`, determine if the board is valid based on the following rules:

- Each row must contain the digits `1-9` without duplicates.
- Each column must contain the digits `1-9` without duplicates.
- Each of the nine `3x3` sub-boxes of the grid must contain the digits `1-9` without duplicates.

Return `true` if the Sudoku board is valid, otherwise return `false`.

Note: A board does not need to be full or be solvable to be valid.

## Linear Search Hash

### Approach

1. Perform 3 consecutive passes of the board along the rows, columns and `3x3` sub-squares.
2. During each iteration along a row, column or sub-square; re-initialize a hash set to track seen numbers for that dimension.
3. Return `false` if a duplicate is found, else return `true`.

### Complexity
- **Time Complexity**: `O(3n^2)` where `n` is the length of a row.
- **Space Complexity**: `O(n)` number tracking sets are never greater than `n` at a time.

## Hash Set

### Approach

1. Create three hash sets:
   - `rows` to track seen numbers in each row.
   - `cols` to track seen numbers in each column.
   - `squares` to track seen numbers in each `3 x 3` sub-box, indexed by `(row//3, col//3)`.
2. Iterate through every cell in the board:
   - Skip empty cells (`.`).
   - Check if the value exists in the corresponding row, column, or sub-box set.
     - If it does, return `false`.
     - Otherwise, add the value to the appropriate sets.
3. If no duplicates are found, return `true`.
## Complexity
- **Time Complexity**: `O(n^2)` where `n` is the size of the Sudoku board.
- **Space Complexity**: `O(n^2)` each hash table will contain n^2 elements in worst case.