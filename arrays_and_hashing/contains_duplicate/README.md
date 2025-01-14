# Contains Duplicate

## Problem Description
Given an integer array ```nums```, return ```true``` if any value appears more than once in the array, otherwise return ```false```.

## Hash Set Length

The solution involves:
1. Converting the array to a hash set.
2. Comparing the length of the hash set to the length of the array.

### Complexity
- **Time Complexity**: `O(n)` where `n` is the number of elements in the array.
- **Space Complexity**: `O(n)` for the hash set.

## Hash Set

The solution involves:
1. Using a hash set to track seen elements.
2. Checking for duplicates while iterating through the array.

### Complexity
- **Time Complexity**: `O(n)` where `n` is the number of elements in the array.
- **Space Complexity**: `O(n)` for the hash set.

## Sorting

The solution involves:
1. Sorting the array.
2. Checking for consecutive duplicate elements.

### Complexity
- **Time Complexity**: `O(n log n)` for sorting and `O(n)` for checking duplicates.
- **Space Complexity**: `O(1)` if sorting in place, otherwise `O(n)`.

## Brute Force

The solution involves:
1. Using nested loops to compare each element with every other element.

### Complexity
- **Time Complexity**: `O(n^2)` where `n` is the number of elements in the array.
- **Space Complexity**: `O(1)` as no additional space is used.