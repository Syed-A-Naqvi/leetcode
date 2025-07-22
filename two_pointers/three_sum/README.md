# 3Sum

## Problem Description

Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` where `nums[i] + nums[j] + nums[k] == 0`, and the indices `i`, `j` and `k` are all distinct.

The output should not contain any duplicate triplets. You may return the output and the triplets in any order.

#### Example 1:
```
Input: nums = [-1,0,1,2,-1,-4]

Output: [[-1,-1,2],[-1,0,1]]
```

Explanation:
- `nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0`.
- `nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0`.
- `nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0`.
The distinct triplets are `[-1,0,1]` and `[-1,-1,2]`.

#### Example 2:
```
Input: nums = [0,1,1]

Output: []
```
Explanation: The only possible triplet does not sum up to `0`.

#### Example 3:
```
Input: nums = [0,0,0]

Output: [[0,0,0]]
```
Explanation: The only possible triplet sums up to `0`.

Constraints:
- `3 <= nums.length <= 1000`
- `10^5 <= nums[i] <= 10^5`


## Solution 1

1. Sort the array. `O(nlogn)`

2. Implement a `functor` struct that hashes three-element vectors and create a c++ unordered set for maintaining a duplcate-free solution set.

3. Iterate for `i` over entire array once (`O(n)`):
    - Let `-vec[i] = target` for the current iteration.
    - using two pointers `j`, `k`, search the subsequent part of the array for two values that sum to `target` while `j < k`.
    - `j++` if `sum < target` and `k--` if `sum > target` (two sum logic).
    - each pointer searches half the remainder of the array $\rightarrow$ `O(1/2 n) + O(1/2 n)` $\rightarrow$ `O(n)`.
    - if a sum is found, create a new solution `[vec[i], vec[j], vec[k]]` and push into the solution set.
4. once the outer loop terminates, return the solution set.


### Complexity
- **Time Complexity**: Outer loop + inner loop $\rightarrow O(n^2)$.
- **Space Complexity**: `O(n)` in the case all elements are part of a solution.