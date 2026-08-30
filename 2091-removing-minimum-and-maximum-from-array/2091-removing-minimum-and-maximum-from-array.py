from typing import List

class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        n = len(nums)

        # Find indices of min and max
        min_index = nums.index(min(nums))
        max_index = nums.index(max(nums))

        left = min(min_index, max_index)
        right = max(min_index, max_index)

        # 1. Remove both from the front
        front = right + 1

        # 2. Remove both from the back
        back = n - left

        # 3. Remove one from each side
        front_back = (left + 1) + (n - right)

        return min(front, back, front_back)