class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        from collections import defaultdict
        freq = defaultdict(int)
        i = res = 0
        for j, x in enumerate(nums):
            freq[x] += 1
            while freq[x] > k:
                freq[nums[i]] -= 1
                i += 1
            res = max(res, j - i + 1)
        return res