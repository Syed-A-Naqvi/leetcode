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

**Approach**: Our first step is to determine the index of the smallest element in $O(\log_{2}n)$ which gives us the offset by which the indices have been rotated. We then conduct a typical binary search and use the offset of the midpoint; `(midpoint + offset) % array.length` for the comparison calculations to account for the rotation. 
```
# finding the offset
1. l = 0, m = 0, r = nums.length-1

2. while (l < r):
    
    m = floor( (l+r) / 2)

    if(nums[m] < r):
        r = m
    else:
        l = m + 1

# binary search
3. offset = l, m_off = 0, l = 0, m = 0, r = nums.length-1

4. while (l <= r):
    m = floor( (l+r)/2 )
    m_off = (m + offset) % nums.length

    if (nums[m_off] == target) {
        return m_off
    }
    else if (nums[m_off] < target) {
        l = m + 1
    }
    if (nums[m_off] > target) {
        r = m - 1
    }

# return -1 if target not found in the array
5. return -1

```

#### Complexity
- **Time Complexity**: $O(\log_{2}n)$ time to find offset and $O(\log_{2}n)$ to find target $\rightarrow O(2\log_{2}n) \rightarrow O(\log_{2}n)$.
- **Space Complexity**: Constant number of additional variables created $\rightarrow$ `O(1)`.