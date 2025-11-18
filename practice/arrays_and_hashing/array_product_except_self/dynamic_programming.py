# Dynamic Programming
#   maintain two running products
#       pref: the ith element is the product of nums elements 0 through i
#       post: the ith element is the products of nums elements i through len(nums)
#   the ith element of the output array can now be calculated based on the element
#   at the next and previous indices

import math

class Solution:
    
    def productExceptSelf(self, nums: list[int]) -> list[int]:
    
        pref = [0]*len(nums)
        post = [0]*len(nums)
        output = []
    
        for i in range(len(nums)):
            if (i == 0):
                pref[i] = nums[i]
            else:
                pref[i] = nums[i]*pref[i-1]

        for i in range(1, len(nums)+1):
            if (i == 1):
                post[-i] = nums[-i]
            else:
                post[-i] = nums[-i] * post[-i+1]
        
        for i in range(len(nums)):
            if(i == 0):
                output.append(post[i+1])
            elif(i == len(nums)-1):
                output.append(pref[i-1])
            else:
                output.append(pref[i-1]*post[i+1])
        
        return output
            
    
nums = [-1,0,1,2,3]
print(Solution().productExceptSelf(nums))