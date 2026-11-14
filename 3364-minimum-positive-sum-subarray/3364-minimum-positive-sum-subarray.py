class Solution:
    def minimumSumSubarray(self, nums: list[int], l: int, r: int) -> int:
        n = len(nums)
        ans = float("inf")

        # Try every possible starting index
        for i in range(n):
            current_sum = 0

            # Extend the subarray to the right
            for j in range(i, n):
                current_sum += nums[j]
                length = j - i + 1

                # Check if length is within bounds and sum is positive
                if l <= length <= r and current_sum > 0:
                    ans = min(ans, current_sum)

        # Return -1 if no valid subarray was found
        return -1 if ans == float("inf") else ans
