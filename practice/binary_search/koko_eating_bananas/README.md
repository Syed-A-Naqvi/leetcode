# Koko Eating Bananas

## Problem Description

You are given an integer array `piles` where `piles[i]` is the number of bananas in the `ith` pile. You are also given an integer `h`, which represents the number of hours you have to eat all the bananas.

You may decide your bananas-per-hour eating rate of `k`. Each hour, you may choose a pile of bananas and eat `k` bananas from that pile. If the pile has less than `k` bananas, you may finish eating the pile but you can not eat from another pile in the same hour.

Return the minimum integer `k` such that you can eat all the bananas within `h` hours.

### Example 1

```python
Input: piles = [1,4,3,2], h = 9

Output: 2
```

Explanation: With an eating rate of 2, you can eat the bananas in 6 hours. With an eating rate of 1, you would need 10 hours to eat all the bananas (which exceeds h=9), thus the minimum eating rate is 2.

### Example 2

```python
Input: piles = [25,10,23,4], h = 4

Output: 25
```

### Constraints

- `1 <= piles.length <= 1,000`
- `piles.length <= h <= 1,000,000`
- `1 <= piles[i] <= 1,000,000,000`

## Solution 1

**Approach**: We perform a binary search for `k` values over the range `[0, max(piles)]`. We consider the upper-half of `piles` if the required hours given the current `k` value exceed `h` and consider the lower half when required hours are `<= h`, updating the minimum `k` value as appropriate.

```python
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

### Complexity

- **Time Complexity**: $O(\log_{2}m)$ iterations of binary search where $m$ is the max value in `piles` and $O(n)$ time per binary search iteration where $n$ is the length of `piles` $\rightarrow O(n\log_{2}m)$.
- **Space Complexity**: Constant number of additional variables created $\rightarrow$ `O(1)`.