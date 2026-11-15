from typing import List

class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        MOD = 1_000_000_007
        even, odd, ans = 1, 0, 0
        parity = 0

        for x in arr:
            parity = (parity + x) & 1
            if parity:
                ans += even
                odd += 1
            else:
                ans += odd
                even += 1
            ans %= MOD

        return ans