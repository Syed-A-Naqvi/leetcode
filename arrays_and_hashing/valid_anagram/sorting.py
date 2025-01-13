# Sorting then comparing
    # if the strings are different lengths return false immediately
    # else sort both strings
    # iterate through both strings at once, as soon as a mismatch is encountered return false
        # may just be able to compare the strings directly (i.e. string1 == string2)
    # return true if all characters are the same
    
    # Time: O(nlogn + mlogm) where n is length of string1 and m is length of string2
    # Space: O(1) or O(n+m) depnding on the sorting algorithm 

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False
        
        return sorted(s) == sorted(t)
        
        

s = 'racecar'
t = 'carrace'

print(Solution().isAnagram(s,t))