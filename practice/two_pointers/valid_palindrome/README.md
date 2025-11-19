# Car Fleet Problem

## Problem Description

Given a string `s`, return `true` if it is a palindrome, otherwise return `false`.

A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

Note: Alphanumeric characters consist of letters `(A-Z, a-z)` and numbers `(0-9)`.

## Solution 1: Lists and Stacks

1. Immediately convert string to lowercase for fewer interval checks. `O(n)`
2. Create two pointers, pointing to first and last string indices.
3. Loop while both pointers are within string index bounds and lower pointer is less than upper pointer. O(n) since each pointer covers half the string.
    - if a pointer pointes to a non-alphanumeric character, incremenet/decrement the pointer as apporopriate.
    - if both pointers point to alpha characters, return `false` if they are different.
4. If no mismatch was found for the entire string, string is a palindrome, return `true`.

### Complexity

- **Time Complexity**: `O(2n) = O(n)` two consecutive string traversals.
- **Space Complexity**: `O(1)` no variable space used.