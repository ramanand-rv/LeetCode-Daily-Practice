class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for l in range(n):
            seen = 0
            cnt = 0
            for r in range(l, n):
                x = nums[r]
                if (seen >> x) & 1 == 0:
                    seen |= 1 << x
                    cnt += 1
                ans += cnt * cnt
        return ans
