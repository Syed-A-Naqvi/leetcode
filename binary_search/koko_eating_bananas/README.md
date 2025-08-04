# Koko Eating Bananas

## Problem Description

You are given an integer array `piles` where `piles[i]` is the number of bananas in the `ith` pile. You are also given an integer `h`, which represents the number of hours you have to eat all the bananas.

You may decide your bananas-per-hour eating rate of `k`. Each hour, you may choose a pile of bananas and eat `k` bananas from that pile. If the pile has less than `k` bananas, you may finish eating the pile but you can not eat from another pile in the same hour.

Return the minimum integer `k` such that you can eat all the bananas within `h` hours.


#### Example 1:
```
Input: piles = [1,4,3,2], h = 9

Output: 2
```
Explanation: With an eating rate of 2, you can eat the bananas in 6 hours. With an eating rate of 1, you would need 10 hours to eat all the bananas (which exceeds h=9), thus the minimum eating rate is 2.


#### Example 2:
```
Input: piles = [25,10,23,4], h = 4

Output: 25
```

#### Constraints:

- `1 <= piles.length <= 1,000`
- `piles.length <= h <= 1,000,000`
- `1 <= piles[i] <= 1,000,000,000`



## Solution 1

**Approach**: Very similar to 1d binary search; maintain three pointers: m, l, and r for the middle, left and right indices of the poriton of the matrix under consideration. Read left-right, top-bottom, we treat the matrix as a single dimension array of size `h*n`. To convert a single dimension index `i` into 2d indices `j`, `k` we perform the calculations `j = Math.floor(i / n)` and `k = i - j*n`. Through this conversion, we are able to abstract away the 2d matrix indexing allowing the algorithm to function as a typical finary search. 

1. Create a function `getMatrixIdxs` that converts a 1d array index `i` into 2d indices `j, k` given the number of columns in the matrix:
- `j = Math.floor(i/n)`
- `k = i - j*n`
- return `[j, k]`

2. Initialize `h = matrix.length`, `n = matrix[0].length`, `l = 0`, `r = (h*n) - 1`.

3. While (`l <= r`):
    - `m = floot( (l+r) / 2)`
    - `j = getMatrixIdxs(n, m)[0]`
    - `k = getMatrixIdxs(n, m)[1]`
    - `if (matrix[j][k] == target) {return true}`
    - `if (matrix[j][k] < target) {l = m+1}`
    - `if (matrix[j][k] > target) {r = m-1}`

2. return `false`.


#### Complexity
- **Time Complexity**: Each iteration divides the total number of elements by two which means there are at most $log_2(h*n)$ constant time iterations $\rightarrow$ $O(log_2(m*n))$.
- **Space Complexity**: Constant number of additional variables created $\rightarrow$ `O(1)`.