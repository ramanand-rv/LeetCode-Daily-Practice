class Solution:
    def minMoves(self, nums: List[int]) -> int:
        lo = min(nums)
        return sum(x - lo for x in nums)
