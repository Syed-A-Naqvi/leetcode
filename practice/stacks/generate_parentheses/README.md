# Generate Parentheses

## Problem Description

Given an integer `n`. Return all well-formed parentheses strings that you can generate with `n` pairs of parentheses.

## Recursion

1. Create a stack member for building the valid parentheses and an array to store the results.
2. Using recursion, conduct a depth first search of the tree consisting of valid parenthesis:
3. If number of opening parentheses < n
    - push "(" onto the stack
    - recursively call function again with number open parentheses += 1
    - pop from the stack upon return
4. If number of closing parentheses < number of opening parentheses
    - push ")" onto the stack
    - recursively call function again with number closed parentheses += 1
    - pop from the stack upon return
5. If number closing parentheses == number opening parentheses == n
    - valid solution found
    - append to results array

### Complexity

- **Time Complexity**: `O($\frac{4^{n}}{\sqrt{n}}$)` recursive tree time complexity.
- **Space Complexity**: `O(n)`algorithm requires at most 2n space in the stack for building valid parentheses.