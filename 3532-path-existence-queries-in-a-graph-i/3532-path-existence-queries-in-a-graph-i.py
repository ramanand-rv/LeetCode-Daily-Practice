class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        cmp = [0] * n
        
        for i in range(1, n):
            cmp[i] = cmp[i - 1] + (abs(nums[i] - nums[i - 1]) > maxDiff)
        
        results = []
        for l, r in queries:
            results.append(cmp[l] == cmp[r])
        
        return results
