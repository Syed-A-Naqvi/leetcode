import heapq

class MedianExtractor:
    
    def __init__(self, data: list):
        
        self.heap = data
        heapq.heapify(self.heap)
        
    def get_median(self):
        
        b = len(self.heap)//2 + 1

        nums = []
            
        for i in range(b):
            nums.append(heapq.heappop(self.heap))
            
        if len(self.heap) % 2 == 0:
            med = (nums[-1] + nums[-2]) / 2
        else:
            med = nums[-2]
            
        for n in nums:
            heapq.heappush(self.heap, n)
                
        return med
    
    def add(self, data):
        for n in data:
            self.data.append(n)
            heapq.heappush(self.heap, n)

numbers = [1,2,3,4,5,6,7,8,9,0,34,2,3,6,5,3,543,52,6,5,47,62,54,236,34734]

dataset = MedianExtractor(numbers)
print(dataset.get_median())
