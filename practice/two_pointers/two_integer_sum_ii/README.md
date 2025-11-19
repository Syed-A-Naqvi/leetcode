# Two Integer Sum II

## Problem Description

Given an array of integers `numbers` that is sorted in non-decreasing order.

Return the indices (**1-indexed**) of two numbers, `[index1, index2]`, such that they add up to a given target number `target` and `index1 < index2`. Note that `index1` and `index2` cannot be equal, therefore you may not use the same element twice.

There will always be **exactly one valid solution**.

Your solution must use $O(1)$ additional space.

Example 1:

```
Input: numbers = [1,2,3,4], target = 3

Output: [1,2]
```

Explanation:

The sum of 1 and 2 is 3. Since we are assuming a 1-indexed array, `index1 = 1`, `index2 = 2`. We return `[1, 2]`.

Constraints:

- `2 <= numbers.length <= 1000`
- `1000 <= numbers[i] <= 1000`
- `1000 <= target <= 1000`

## Solution 1

1. Create two pointers `i` and `j` pointing to the first and last elements of the array respectively.
2. Loop while `i < j`:
    - Compare `value = target - array[i]` with `array[j]`
        - if `value < array[j]` then `j--`
        - if `value > array[j]` then `i++`
        - if `value == array[j]` then we have found the sum; return `[i+1, j+1]` due to 1-indexing
    - *note that array being non-increasing means it is guranteed that `array[i] <= array[i+1]` and `array[j] <= array[j+1]`

### Complexity

- **Time Complexity**: the two pointers both account for `n/2` iterations $\rightarrow$ `O(n)`.
- **Space Complexity**: `O(1)` constant amount of pointers used.