from math import gcd
from typing import List


class Solution:
    def gcdSum(self, nums: List[int]) -> int:
        n = len(nums)
        a = [0] * n
        mx = 0

        for i in range(n):
            mx = max(mx, nums[i])
            a[i] = gcd(nums[i], mx)

        a.sort()

        ans = 0
        l, r = 0, n - 1
        
        while l < r:
            ans += gcd(a[l], a[r])
            l += 1
            r -= 1

        return ans
