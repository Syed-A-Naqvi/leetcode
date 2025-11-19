# Daily Temperatures

## Problem Description

You are given an array of integers `temperatures` where `temperatures[i]` represents the daily temperatures on the `ith` day.

Return an array `result` where `result[i]` is the number of days after the `ith` day before a warmer temperature appears on a future day. If there is no day in the future where a warmer temperature will appear for the `ith` day, set `result[i]` to `0` instead.

## Stack Approach

1. Create a stack of size `n` where `n = temperatures.size()`

2. Iterate through the temperatures array and push each index onto the stack if:
    - the stack is empty, or
    - the temperature at the current index is less than the temperature at the previous (stack.top()) index

3. If the temperature at the current index is larger than the temperature at the previous index:
    - set value `temperatures[stack.top()] = currIndex - stack.top()` (calculates the number of days to warmer temperature)
    - pop the last element off the stack (stack.pop())
    - repeat this process until current index temperature is greater than previous or the stack is empty and then push the current index onto the stack

4. Once the temperatures array has been exhausted, set temperatures for all remaining indecies in the stack to 0

### Complexity

- **Time Complexity**: `O(2n)` in the worst case (temperatures is sorted in desc order, expect for last element which is largest).
- **Space Complexity**: `O(n)` in the worst case for the stack.