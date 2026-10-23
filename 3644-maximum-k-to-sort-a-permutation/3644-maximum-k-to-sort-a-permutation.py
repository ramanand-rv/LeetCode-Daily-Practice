class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        k = -1  # all bits set (infinite ones in two's complement)
        for i, x in enumerate(nums):
            if x != i:
                k &= x
                if k == 0:
                    return 0
        return max(k, 0)
