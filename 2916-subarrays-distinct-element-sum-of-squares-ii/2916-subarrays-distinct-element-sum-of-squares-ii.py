class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        cnt = [0] * (n + 1)
        tot = [0] * (n + 1)
        last = {}
        ans = 0

        for r, x in enumerate(nums):
            p = last.get(x, -1)

            c = 0
            s = 0
            i = n - p - 1
            while i > 0:
                c += cnt[i]
                s += tot[i]
                i -= i & -i

            gain = (r - p) * (r - p) - 2 * (s - p * c)
            ans = (ans + (n - r) * gain) % MOD

            i = n - p
            while i <= n:
                cnt[i] += 1
                tot[i] += p
                i += i & -i

            last[x] = r

        return ans
