class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        MOD = 10**9 + 7
        bit_count = [0] * 32

        for num in nums:
            for b in range(32):
                if num & (1 << b):
                    bit_count[b] += 1

        ans = 0
        for _ in range(k):
            cur = 0
            for b in range(32):
                if bit_count[b] > 0:
                    bit_count[b] -= 1
                    cur |= 1 << b
            ans = (ans + cur * cur) % MOD
        return ans
