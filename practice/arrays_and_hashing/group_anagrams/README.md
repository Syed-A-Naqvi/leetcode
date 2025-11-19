# Group Anagrams

## Problem Description

Given an array of strings `strs`, group all anagrams together into sublists. The output may be returned in any order.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

## Bucket Sort with Hashing

### Approach

1. Iterate through each string in the input array `strs`.
2. Count the occurrences of each character using a frequency array of size 26, where each index represents a letter of the alphabet.
3. Convert the frequency array into a tuple (immutable and hashable) to serve as a unique key that identifies anagrams.
4. Use a hash table (dictionary) to group strings:
   - The **key** is the character frequency tuple.
   - The **value** is a list of strings that share the same character frequency (i.e., are anagrams).
5. For each string:
   - Compute its character frequency tuple.
   - Add the string to the corresponding list in the hash table.
6. After processing all strings, collect and return the values (lists of grouped anagrams) from the hash table.

### Complexity

- **Time Complexity**: `O(m*n)` where `m` is the number of strings and `n` is the length of the longest string. 
- **Space Complexity**: `O(m*n)` the dictionary will take up as much space as `strs`.