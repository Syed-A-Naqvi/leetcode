# Longest Consecutive Subsequence

## Problem Description

Given an array of integers `nums`, return the length of the longest consecutive sequence of elements that can be formed.

A consecutive sequence is a sequence of elements in which each element is exactly `1` greater than the previous element. The elements do not have to be consecutive in the original array.

The algorithm must run in O(n) time.

## Hash Set

### Approach

1. Convert the `nums` array to a hash set.
2. Iterate over the set once, find all sequence starts by checking if `curr_val - 1` not in the set.
3. Begin at each start value, increment until value not in set and record length.
4. Return longest length.

### Complexity
- **Time Complexity**: `O(4n)` worst case where `n` is the length of `nums` array and each element is its own sequence.
- **Space Complexity**: `O(n)` for sequence starts array.