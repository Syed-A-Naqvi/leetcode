class Solution:
    def hasDuplicate(self, nums: list[int]) -> bool:
        
        if len(nums) == 0:
            return False
        
        s = set((nums[0],))
        for i in range(1,len(nums)):
            if nums[i] in s:
                return True
            else:
                s.add(nums[i])
        return False

print(Solution().hasDuplicate([]))