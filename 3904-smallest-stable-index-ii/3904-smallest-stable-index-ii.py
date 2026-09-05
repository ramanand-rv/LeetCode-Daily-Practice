class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        max_so_far = -10**9
        cand = 0
        c_max = 0
        n = len(nums)

        for i in range(n):
            max_so_far = max(max_so_far, nums[i])

            if i == cand:
                c_max = max_so_far

            if nums[i] < c_max - k:
                cand = i + 1

        return cand if cand < n else -1