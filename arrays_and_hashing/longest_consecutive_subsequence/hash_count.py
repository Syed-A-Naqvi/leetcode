# Hash Sequence Starts
    # convert the nums list to a set
    # iterate once and fine all sequence starts by checking if curr_val - 1 is in nums
    # for each start value, increment until value not in nums and record length
    # return longest length

from typing import List
from collections import defaultdict

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        nums = set(nums) # no additional space

        # O(n) space and time
        starts = [] 
        for val in nums:
            if (val-1) not in nums:
                starts.append(val)
        
        streak = 0
        longest_streak = streak     
        # worst case O(2n) if len(s) == len(nums)
        for s in starts:
            val = s
            while (val in nums):
                streak += 1
                val += 1
            longest_streak = max(longest_streak, streak)
            streak = 0
            
        return longest_streak

            

print(Solution().longestConsecutive([2,20,4,10,3,4,5]))