class Solution:
    def minMoves(self, nums: list[int]) -> int:
        # Since we can ONLY increment elements, we cannot decrease the maximum element.
        # Therefore, the optimal target value X that all elements must reach is max(nums).

        # The number of moves to convert an element `x` to `X` is (X - x).
        # Total moves = sum(X - x) for all x in nums.
        # This simplifies to: n * X - sum(nums).

        n = len(nums)
        max_val = max(nums)
        sum_val = sum(nums)

        return n * max_val - sum_val
