from collections import deque
from typing import List


class Solution:
    def countNonDecreasingSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        starts = deque()  # stores plateau start indices
        r = n - 1
        ans = 0
        water = 0

        # Process each left endpoint from right to left
        for l in range(n - 1, -1, -1):
            x = nums[l]

            # Flood plateaus to the right that are <= x
            while starts and nums[starts[0]] <= x:
                s = starts.popleft()  # pop front plateau
                end = starts[0] if starts else r + 1
                water += (x - nums[s]) * (end - s)

            # New plateau starts at l
            starts.appendleft(l)

            # Shrink window from right while water > k
            while water > k:
                # The bar at r belongs to the last plateau
                water -= nums[starts[-1]] - nums[r]
                # If the last plateau is only index r, remove it
                if starts[-1] == r:
                    starts.pop()
                r -= 1

            # All subarrays ending at <= r starting at l are good
            ans += r - l + 1

        return ans
