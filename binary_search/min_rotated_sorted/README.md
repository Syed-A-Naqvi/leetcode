# Find Minimum in Rotated Sorted Array

## Problem Description

You are given an array of length `n` which was originally sorted in ascending order. It has now been rotated between `1` and `n` times. For example, the array `nums = [1,2,3,4,5,6]` might become:

- `[3,4,5,6,1,2]` if it was rotated `4` times.

- `[1,2,3,4,5,6]` if it was rotated `6` times.

Notice that rotating the array `4` times moves the last four elements of the array to the beginning. Rotating the array `6` times produces the original array.

Assuming all elements in the rotated sorted array `nums` are unique, return the minimum element of this array.

A solution that runs in `O(n)` time is trivial, can you write an algorithm that runs in `O(log n)` time?


#### Example 1:
```
Input: nums = [3,4,5,6,1,2]

Output: 1
```
#### Example 2:
```
Input: nums = [4,5,0,1,2,3]

Output: 0
```
#### Example 3:
```
Input: nums = [4,5,6,7]

Output: 4
```
#### Constraints:

- `1 <= nums.length <= 1000`
- `-1000 <= nums[i] <= 1000`



## Solution 1

**Approach**: We perform a binary search for `k` values over the range `[0, max(piles)]`. We consider the upper-half of `piles` if the required hours given the current `k` value exceed `h` and consider the lower half when required hours are `<= h`, updating the minimum `k` value as appropriate.
```
#we can initialize min_k = r as it gurantees h = piles.length
1. r = max(piles), min_k = r, l = 0

2. while (l <= r):
    
    set k = int( (l+r)/2 ), curr_h = 0
    
    for i in [0, piles.length]:
        curr_h += ceiling(piles[i]/k)
    
    if(curr_h <= h):
        # we can afford to reduce k -> search lower half
        r = k-1
        min_k = k
    else:
        # k is too small -> search upper half
        l = k+1

3. return min_k
```

#### Complexity
- **Time Complexity**: $O(\log_{2}m)$ iterations of binary search where $m$ is the max value in `piles` and $O(n)$ time per binary search iteration where $n$ is the length of `piles` $\rightarrow O(n\log_{2}m)$.
- **Space Complexity**: Constant number of additional variables created $\rightarrow$ `O(1)`.