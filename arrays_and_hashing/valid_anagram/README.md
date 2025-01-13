# Valid Anagram

## Problem Description

Given two strings `s` and `t`, return true if the two strings are anagrams of each other, otherwise return false.

## Sorting

### Approach

1. If the strings are different lengths return `false`.
2. If strings are the same length iterate over both strings at once and return `false` as
soon as a mismatch is found.
3. Return `true` if no mismatches are found.

### Complexity
- **Time Complexity**: `O(nlogn + n)` where `n` is the length of the strings.
- **Space Complexity**: `O(1)` no additional space required.

## Hash Table

### Approach

1. If strings are different lengths return `false` immediately.
2. If strings are the same length, create character-count dictionaries for both strings.
3. Return dict1 == dict2.

## Complexity
- **Time Complexity**: `O(3n)` where `n` is the size of string1 and string2.
- **Space Complexity**: `O(2n)` creating two dictionaries of size n.

## Optimal Hash Table

### Approach

1. If strings are different lengths return `false` immediately.
2. If strings are the same length, create a single character count dictionary.
3. Iterate over both strings hashing each character into the dictionary.
4. For string1, increment counts by 1, for string2, decrement counts by 1.
4. If the strings are anagrams, all character counts will be 0, return `true`, else return `false`

## Complexity
- **Time Complexity**: `O(3n)` where `n` is the length of strings 1 and 2.
- **Space Complexity**: `O(n)` since only one dictionary created.