# Brute force method
    # Iterates through entire list for each element and searches for a duplicate
    # Time: O(n^2)
    # Space: O(1)

class Solution:
    def hasDuplicate(self, nums: list[int]) -> bool:
        
        if(len(nums) == 0):
            return False
        
        for i in range(0, len(nums)):
            for j in range(i+1, len(nums)):
                if (nums[j] == nums[i]):
                    print(f"{nums[j]} == {nums[i]}")
                    return True
        
        return False

print(Solution().hasDuplicate([1,2,3]))
