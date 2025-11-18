# Product of Array Except Self

## Problem Description

Given an array `nums`, return an array `output` where each element at index `i` is the product of all elements in `nums` except the one at index `i`. Division is not allowed, and the solution must run in `O(n)` time complexity.

## Dynamic Programming

### Approach

1. Calculate a prefix product array where `pref[i]` is the product of all elements from index `0` to `i`.
2. Calculate a postfix product array where `post[i]` is the product of all elements from index `i` to the last index.
3. Use the prefix and postfix arrays to compute the output for each index:
   - For the first index, use only the postfix array.
   - For the last index, use only the prefix array.
   - For all other indices, multiply the prefix of the previous index with the postfix of the next index.

## Complexity

- **Time Complexity**: `O(n)` since we traverse the array three times—once for `pref`, once for `post`, and once for constructing `output`.

- **Space Complexity**: `O(n)` due to the additional space used by the `pref` and `post` arrays.