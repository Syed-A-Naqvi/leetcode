# Binary Search

## Problem Description

You are given an array of distinct integers `nums`, sorted in ascending order, and an integer `target`.

Implement a function to search for `target` within `nums`. If it exists, then return its index, otherwise, return `-1`.

Your solution must run in $O(logn)$ time.

### Example 1

```python
Input: nums = [-1,0,2,4,6,8], target = 4

Output: 3
```

### Example 2

```python
Input: nums = [-1,0,2,4,6,8], target = 3

Output: -1
```

### Constraints

- 1 <= nums.length <= 10000.
- 10000 < nums[i], target < 10000
- All the integers in nums are unique.

## Solution 1

**Approach**: Maintain three pointers: m, l, and r for the middle, left and right indices of the portion of the array under consideration. If the target index is not `m` then since the array is sorted we know if `nums[m] > target` the index must be in `[l,m)` and if `nums[m] < target` the index must be in `(m,r]`.

1. Initialize l = 0, r = nums.length-1 and m = int(r/2).
2. While (l <= r):
    - if (nums[l] == target) {return l}
    - if (nums[m] == target) {return m}
    - if (nums[r] == target) {return r}
    - if (nums[m] < target) {l = m+1}
    - if (nums[m] > target) {r = m-1}
2. return -1.

### Complexity

- **Time Complexity**: Each iteration divides the array by two which means there are at most $log_2(n)$ iterations for an array of length `n`, each of constant time $\rightarrow$ $O(log_2(n))$.
- **Space Complexity**: Constant number of additional variables created $\rightarrow$ `O(1)`.