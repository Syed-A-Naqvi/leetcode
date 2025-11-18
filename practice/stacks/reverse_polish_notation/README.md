# Reverse Polish Notation

## Problem Description

You are given an array of string tokens that represents a valid arithmetic expression in Reverse Polish Notation.

Return the integer that represents the evaluation of the expression.

The operands may be integers or the results of other operations.
The operators include '+', '-', '*', and '/'.
Assume that division between integers always truncates toward zero.

## Stack Operations

1. Iterate through the token array.
2. If a token is an integer push onto stack.
3. If a token is an operator, pop the last two number off the stack and use conditionals to perform the appropriate calculations.
4. Push the answer back onto the stack and repeat until all tokens processed.

### Complexity
- **Time Complexity**: `O(n)` where 'n' is the number of token strings.
- **Space Complexity**: `O(1)` the stack will never store more than two elements at a time.