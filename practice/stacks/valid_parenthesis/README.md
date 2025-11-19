# Contains Duplicate

## Problem Description

Given a string `s` consisting of the following characters: `(`, `)`, `{`, `}`, `[` and `]`.

The input string `s` is valid if and only if:

- Every open bracket is closed by the same type of close bracket.
- Open brackets are closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.

Return `true` if `s` is a valid string, and `false` otherwise.

## Bracket Stack

### Approach

1. Initialize an empty stack and a bracket-pair hash map.
2. Traverse the bracket string.
3. If opening bracket is encountered, push onto stack.
4. If stack is non-empty and last opening bracket on stack matches current closing bracket, pop last element from stack, else return false.
5. After for loop, return false if stack non-empty, else return true.

### Complexity

- **Time Complexity**: `O(n)` where `n` is the length of the parenthesis string.
- **Space Complexity**: `O(n)` for the stack in worst case when all items are opening braces.