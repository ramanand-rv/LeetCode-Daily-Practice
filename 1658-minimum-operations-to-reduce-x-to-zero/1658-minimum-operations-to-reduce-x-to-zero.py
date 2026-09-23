class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        n = len(nums)
        total = sum(nums)
        target = total - x

        if target < 0:
            return -1
        if target == 0:
            return n

        left = 0
        curr = 0
        longest = -1

        for right in range(n):
            curr += nums[right]
            while left <= right and curr > target:
                curr -= nums[left]
                left += 1
            if curr == target:
                longest = max(longest, right - left + 1)

        return -1 if longest == -1 else n - longest
