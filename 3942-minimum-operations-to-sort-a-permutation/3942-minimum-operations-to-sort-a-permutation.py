class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        shift = nums.index(0)

        def ring(k: int) -> int:
            return nums[(shift + k) % n]

        if all(ring(k) == k for k in range(n)):
            return min(shift, n - shift + 2)

        if all(ring(k) == (n - k) % n for k in range(n)):
            return min(shift + 2, n - shift)

        return -1
