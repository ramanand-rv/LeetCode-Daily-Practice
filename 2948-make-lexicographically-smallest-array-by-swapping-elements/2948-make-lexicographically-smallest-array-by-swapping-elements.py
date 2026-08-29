class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n = len(nums)
        
        # Pair each value with its original index
        pairs = [(nums[i], i) for i in range(n)]
        
        # Sort by value
        pairs.sort(key=lambda x: x[0])
        
        # Identify groups (contiguous blocks separated by gap > limit)
        groups = []
        start = 0
        for i in range(1, n + 1):
            if i == n or pairs[i][0] - pairs[i-1][0] > limit:
                groups.append((start, i - 1))
                start = i
        
        # Process each group
        for s, e in groups:
            length = e - s + 1
            values = [pairs[i][0] for i in range(s, e + 1)]
            indices = [pairs[i][1] for i in range(s, e + 1)]
            
            # Sort indices to assign values in ascending index order
            indices.sort()
            
            for i in range(length):
                nums[indices[i]] = values[i]
        
        return nums
