# Hash Groups
    # create new default list dictionary called groups
    # map each string to an array of character counts indexed by character alphabet position
    # append string to list in the groups dict, using tuple version of its character count array as key
    # repeat for all strings
        # really clever, maps each string to a hash value such that all anagrams of the string have the same hash
        # then uses the hash value to index a list in the default dict and appends the anagram to the list
        # allows for the grouping of all anagrams after a single pass of the strs array
        # Hasing is really powerful!
    
    # Time: O(m*n) where m is the number of strings and n is the length of the longest string
    # Space: O(m) dict or list with m elements

from collections import defaultdict

class Solution:

    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        
        groups = defaultdict(list)
        
        for s in strs:
            counts = [0]*26
            for c in s:
                counts[ord(c) - ord('a')] += 1
            groups[tuple(counts)].append(s)
        
        return list(groups.values())
    

strs = ["act","pots","tops","cat","stop","hat"]
print(strs)
print(Solution().groupAnagrams(strs=strs))