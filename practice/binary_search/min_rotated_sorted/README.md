# Find Minimum in Rotated Sorted Array

## Problem Description

You are given an array of length `n` which was originally sorted in ascending order. It has now been rotated between `1` and `n` times. For example, the array `nums = [1,2,3,4,5,6]` might become:

- `[3,4,5,6,1,2]` if it was rotated `4` times.

- `[1,2,3,4,5,6]` if it was rotated `6` times.

Notice that rotating the array `4` times moves the last four elements of the array to the beginning. Rotating the array `6` times produces the original array.

Assuming all elements in the rotated sorted array `nums` are unique, return the minimum element of this array.

A solution that runs in `O(n)` time is trivial, can you write an algorithm that runs in `O(log n)` time?


### Example 1

```python
Input: nums = [3,4,5,6,1,2]

Output: 1
```

### Example 2

```python
Input: nums = [4,5,0,1,2,3]

Output: 0
```

### Example 3

```python
Input: nums = [4,5,6,7]

Output: 4
```

### Constraints

- `1 <= nums.length <= 1000`
- `-1000 <= nums[i] <= 1000`

## Solution 1

**Approach**: We begin with a binary search setup with pointers `l, m, r` and loop while `l < r`. We define `m` as $\lfloor (l+r) / 2 \rfloor$ which ensures `m < r` for the duration of the loop. The goal is to position the `l` pointer on the minimum value in the array. If `nums[m] < nums[r]` then either `nums[m]` is the minimum or the minimum is to the left of `m`; we thus set `r = m`. If `numns[m] > nums[r]` then we know the minimum must be to the right of `m` and we set `l = m+1`. Since we only increment `l` **once** past `m` when we know the minimum is to the right of `m`, we guarantee the algorithm converges to `l=r` when `l` points to the minimum at which point we return `l`.

```python
1. l = 0, r = nums.length-1

2. while (l < r):
    
    m = floor( (l+r) / 2)

    if(nums[m] < r):
        r = m
    else:
        l = m+1

3. return nums[l]
```

### Complexity

- **Time Complexity**: $O(\log_{2}m)$ iterations of binary search for min array value.
- **Space Complexity**: Constant number of additional variables created $\rightarrow$ `O(1)`.