# Largest Rectangle in Histogram

## Problem Description

You are given an array of integers `heights` where `heights[i]` represents the height of a bar. The width of each bar is `1`.

Return the area of the largest rectangle that can be formed among the bars.

Note: This chart is known as a histogram.

## Solution 1: Stacks

1. Create a new `Bar` class that stores the height and index of a bar.

2. Create a `bars` stack for `Bar` objects. 

2. Loop until `i` > `heights.length`:
    - If `ith` height `==` current top of stack:
      - increment `i`.
      - set new effective index to `i`.
    - If `ith` height `>` current top of stack:
      - create and push a new bar onto stack at effective index.
      - increment `i`.
      - set the new effective index to `i`.
    - If `ith` height `<` current top of stack:
      - pop a bar off the stack and calculate area using height = `bar.height` and width = `i - bar.index`.
      - index of popped bar is now the effective index.
      - update current max area depending on calculated area.

3. After heights array has been exhausted, loop until `bars` stack is empty:
  - pop a bar off the stack and calculate area using height = `bar.height` and width = `i - bar.index`.
  - update best area if appropriate.

4. return best area.


### Complexity
- **Time Complexity**: `O(n)`; in the worst case, each element of the heights array is processed twice `O(2n) = O(n)`.
- **Space Complexity**: `O(n)` the stack will take at most and additional space of `n`.