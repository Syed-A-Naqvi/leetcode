# Search in Rotated Sorted Array

## Problem Description

You are given an array of length `n` which was originally sorted in ascending order. It has now been rotated between `1` and `n` times. For example, the array `nums = [1,2,3,4,5,6]` might become:

- `[3,4,5,6,1,2]` if it was rotated `4` times.
- `[1,2,3,4,5,6]` if it was rotated `6` times.

Given the rotated sorted array `nums` and an integer `target`, return the index of `target` within `nums`, or `-1` if it is not present.

You may assume all elements in the sorted rotated array nums are unique,

A solution that runs in `O(n)` time is trivial, can you write an algorithm that runs in `O(log n)` time?

#### Example 1:
```
Input: nums = [3,4,5,6,1,2], target = 1

Output: 4
```

#### Example 2:
```
Input: nums = [3,5,6,0,1,2], target = 4

Output: -1
```
#### Constraints:

- `1 <= nums.length <= 1000`
- `-1000 <= nums[i] <= 1000`
- `-1000 <= target <= 1000`




## Solution 1

**Approach**: We begin with a binary search setup with pointers `l, m, r` and loop while `l < r`. We define `m` as $\lfloor (l+r) / 2 \rfloor$ which ensures `m < r` for the duration of the loop. The goal is to position the `l` pointer on the minimum value in the array. If `nums[m] < nums[r]` then either `nums[m]` is the minimum or the minimum is to the left of `m`; we thus set `r = m`. If `numns[m] > nums[r]` then we know the minimum must be to the right of `m` and we set `l = m+1`. Since we only increment `l` **once** past `m` when we know the minimum is to the right of `m`, we guarantee the algorithm converges to `l=r` when `l` points to the minimum at which point we return `l`.
```
1. l = 0, r = nums.length-1

2. while (l < r):
    
    m = floor( (l+r) / 2)

    if(nums[m] < r):
        r = m
    else:
        l = m+1

3. return nums[l]
```

#### Complexity
- **Time Complexity**: $O(\log_{2}m)$ iterations of binary search for min array value.
- **Space Complexity**: Constant number of additional variables created $\rightarrow$ `O(1)`.