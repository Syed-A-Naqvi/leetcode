# Top K Frequent Elements

## Problem Description

Given an integer array 'nums' and an integer 'k', return the 'k' most frequent elements within the array.

The test cases are generated such that the answer is always unique.

The output may be returned in any order.

## Bucket Sort with Hashing

### Approach

1. Create a dictionary `counts` for tracking element counts and a list of buckets where `len(buckets) == len(nums)+1`.
2. Pass through `nums` once and track the counts for all elements.
3. Pass through `counts` once and append each key into the bucket whose index corresponds to that key's count value.
4. Iterate through the buckets list in reverse, appending each element into the `answer` list.
5. return `answer` when `len(answer) == k`.

### Complexity

- **Time Complexity**: `O(3n)` worst case when `k == len(nums)`. 
- **Space Complexity**: `O(4n)` worst case when `k == len(nums)`.