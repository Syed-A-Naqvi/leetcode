# Hash Map
    # start iterating through the array with i = 0 and create an empty hash map
    # calculate difference = target - array[i]
    # if difference is in hashmap return [i,map[difference]]
    # else set map[array[i]] = i and i+=1
    # Time: O(n)
    # Space: O(n)

class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        
        values = {}
        
        for i in range(len(nums)):
            
            difference = target - nums[i]
            
            if(difference in values):
                j = values[difference]
                return [i,j]
            else:
                values[nums[i]] = i

nums = [3,4,3]
target = 6

output = Solution().twoSum(nums=nums, target=target)

print(output)