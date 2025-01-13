# Hash Set
    # set membership checks calculate the hash value of each element used to index into the internal hash table
    # if there is a collision, the element exists in the table and a duplicate exists (return true), false otherwise
    # Time: O(n)
    # Space: O(n)

class Solution:
    def hasDuplicate(self, nums: list[int]) -> bool:
        
        seen = set()
        
        for n in nums:
            if n in seen:
                return True
            else:
                seen.add(n)
        
        return False
        
print(Solution().hasDuplicate([1,2,3,1]))