# Bucket Sorting with Hashing
    # first create a dictionary for the integer elements and their counts
    # next create an array of arrays (buckets) with length = len(nums)+1
        # the indicies of the buckets now correspond to 

class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        
        counts = {}
        buckets = [[] for _ in range((len(nums)+1))]
        
        for n in nums:
            counts[n] = counts.get(n, 0) + 1
        for value, cnt in counts.items():
            buckets[cnt].append(value)
        
        answer = []
        for b in range(1, len(buckets)+1):
            for i in range(len(buckets[-b])):
                answer.append(buckets[-b][i])
                if len(answer) == k:
                    return answer

nums = [10,20]
k = 2

print(Solution().topKFrequent(nums, k))