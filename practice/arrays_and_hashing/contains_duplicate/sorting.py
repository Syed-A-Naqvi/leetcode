# Sorting method
    # Sorts list in nlogn time and then does a single pass in n time, checking if next element == current element 
    # Time: O(nlogn + n) = O(nlogn)
    # Space: O(1) or O(n) depending on the sorting algorithm

class Solution:
    def hasDuplicate(self, nums: list[int]) -> bool:
        
        if(len(nums) == 0 or len(nums) == 1):
            return False
        
        nums.sort()
        
        for i in range(0, len(nums)-1):
            if (nums[i] == nums[i+1]):
                return True
        
        return False
        

print(Solution().hasDuplicate([1,2,3,3]))
