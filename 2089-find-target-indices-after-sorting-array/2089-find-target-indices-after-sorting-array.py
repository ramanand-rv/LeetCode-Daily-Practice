class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        left = sum(x < target for x in nums)
        right = sum(x <= target for x in nums)
        return list(range(left, right))
