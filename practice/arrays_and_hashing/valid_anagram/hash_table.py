# Sorting then comparing
    # if the strings are different lengths return false immediately
    # else create one hash table for each string storing character counts
    # return true if the hash tables are the same
    
    # Time: O(n) where n is length of string1 and string2
    # Space: O(n+m) depnding on the sorting algorithm 

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False
        
        counts, countt = {}, {}
        
        for i in range(len(s)):
            counts[s[i]] = 1 + counts.get(s[i], 0)
            countt[t[i]] = 1 + countt.get(t[i], 0)
        
        return countt == counts
        

s = 'racecar'
t = 'carrace'

print(Solution().isAnagram(s,t))