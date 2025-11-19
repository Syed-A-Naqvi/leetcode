# Two Sum

## Problem Description

Given an array of integers `nums` and an integer `target`, return the indices `i` and `j` such that `nums[i] + nums[j] == target` and `i != j`.

It can be assumed that every input has exactly one pair of indices `i` and `j` that satisfy the condition.

Return the answer with the smaller index first.

## Hash Map

### Approach

1. Create a dictionary `index` with array elements as keys and indices as values.
2. Begin iterating for `i` in `len(nums)` and calculate `diff = target - nums[i]` for each `i`
3. If `diff` is a key in `index`, return `[i, index[diff]]` or `[index[diff], i]`
4. If `diff` is not a key, insert `index[nums[i]] = i`
5. If no pair is found, return `[]`

### Complexity

- **Time Complexity**: `O(n)` where `n` is the length of `nums` array.
- **Space Complexity**: `O(n)` for `index` dictionary.