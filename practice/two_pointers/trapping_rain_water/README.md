# Trapping Rain Water

## Problem Description

You are given an array of non-negative integers `height` which represent an elevation map. Each value `height[i]` represents the height of a bar, which has a width of `1`.

Return the maximum area of water that can be trapped between the bars.

#### Example 1:
```
Input: height = [0,2,0,3,1,0,1,3,2,1]

Output: 9
```

#### Constraints:
- `1 <= height.length <= 1000`
- `0 <= height[i] <= 1000`


## Solution 1

**Approach**: The amount of water that can be trapped above any position in the height array is limited by the minimum of the maximum heights on either side. Begin with two pointers `l` and `r` pointing to the first element at each end of the height array. The first position of either pointer will always trap `0` water as the maximums heights on one of the sides will default to `0`. First we increment/decrement the pointer with the smaller height, suppose we increment `l`. The new maximum to its `left` will be updated based on the previous position and we use this value minus `height[l]` to determine the amount of water trapped at this location, adding it to a running total. We again increment/decrement the pointer with the lesser height, update its `max_left_height` or `max_right_height` as appropriate, calculate the trapped water above its position, add it to the running total and continue this process until `l > r`.

1. Initialize:
    - `l = 0`
    - `r = height.length-1`
    - `max_left = max_right = 0`
    - `total_trapped = 0`

2. While (`l < r`):
    - if (`height[l] < height[r]`):
        - `trapped = max_left - height[l]`
        - if `trapped > 0`: `total_trapped += trapped`
        - if `max_left < height[l]`: `max_left = height[l]` 
        - l++
    - else:
        - `trapped = max_right - height[r]`
        - if `trapped > 0`: `total_trapped += trapped`
        - if `max_right < height[r]`: `max_right = height[r]`
        - r--

3. return `total_trapped`

### Complexity
- **Time Complexity**: Total combined elements traversed by both pointers is `n` $\rightarrow$ `O(n)`.
- **Space Complexity**: Constant number of additional variables created $\rightarrow$ `O(1)`.