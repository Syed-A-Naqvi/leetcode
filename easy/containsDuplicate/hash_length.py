# Hash Length
    # Convert the entire list into a set
    # if len(set) == len(list) there is no duplicate
    # if len(set) < len(list) there exists at least 1 duplicate

class Solution:
    def hasDuplicate(self, nums: list[int]) -> bool:
        return len(set(nums)) < len(nums)

print(Solution().hasDuplicate([1,2,3,3]))