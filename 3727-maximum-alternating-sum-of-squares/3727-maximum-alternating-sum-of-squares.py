class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        n = len(nums)
        a = [x * x for x in nums]
        a.sort()

        ans = 0
        k = n // 2

        for i in range(k):
            ans -= a[i]
        for i in range(k, n):
            ans += a[i]

        return ans
