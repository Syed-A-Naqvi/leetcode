# Sorting then comparing
    # if the strings are different lengths return false immediately
    # else create a single hash table
        # for string1, hash each element and incremenet value in table by 1
        # for string2, hash each element and decrement each value by 1
        # if strings are anagrams, hash table will contain all 0s
    
    # Time: O(n) where n is length of string1 and string2
    # Space: O(1) since count will contain at most 26 elements 

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False
        
        count = {}
        
        for i in range(len(s)):
            count[s[i]] = count.get(s[i], 0) + 1
            count[t[i]] = count.get(t[i], 0) - 1 
        
        for c in count.values():
            if c != 0:
                return False
        return True
        

s = ''
t = ''

print(Solution().isAnagram(s,t))