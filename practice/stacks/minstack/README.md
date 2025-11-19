# Min Stack

## Problem Description

Design a stack class that supports the push, pop, top, and getMin operations.

- MinStack() initializes the stack object.
- void push(int val) pushes the element val onto the stack.
- void pop() removes the element on the top of the stack.
- int top() gets the top element of the stack.
- int getMin() retrieves the minimum element in the stack.

Each function should run in O(1) time.

## Double Stack

1. Create two stacks, one for all values and one for minimum values.

### push Method

1. Push value onto regular stack.
2. If minimum stack is empty, or top of minimum stack >= value being pushed, push value onto minimum stack.

### pop Method

1. Pop item from regular stack.
2. If current minimum (top of minimum stack) === popped item, pop minimum stack.

### top Method

1. Return top element of regular stack without popping.

### getMin Method

1. Return the top element of the minimum stack without popping.

### Complexity

- **Time Complexity**: `O(1)` all operations run in constant time.
- **Space Complexity**: `O(2n)` will require 2n space in the worst case (i.e. elements pushed in descending order).