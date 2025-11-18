# Search a 2D Matrix

## Problem Description

You are given an `h x n` 2-D integer array `matrix` and an integer `target`.

- Each row in `matrix` is sorted in non-decreasing order.
- The first integer of every row is greater than the last integer of the previous row.

Return `true` if target exists within matrix or `false` otherwise.

Can you write a solution that runs in `O(log(h * n))` time?

### Example 1

```python
Input: matrix = [[1,2,4,8],[10,11,12,13],[14,20,30,40]], target = 10

Output: true
```

### Example 2

```python
Input: matrix = [[1,2,4,8],[10,11,12,13],[14,20,30,40]], target = 15

Output: false
```

### Constraints

- `h == matrix.length`
- `n == matrix[i].length`
- `1 <= h, n <= 100`
- `-10000 <= matrix[i][j], target <= 10000`

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

4. return `false`.

### Complexity

- **Time Complexity**: Each iteration divides the total number of elements by two which means there are at most $log_2(h*n)$ constant time iterations $\rightarrow$ $O(log_2(m*n))$.
- **Space Complexity**: Constant number of additional variables created $\rightarrow$ `O(1)`.
