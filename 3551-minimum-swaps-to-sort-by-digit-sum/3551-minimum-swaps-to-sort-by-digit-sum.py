class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        def digit_sum(x: int) -> int:
            s = 0
            while x > 0:
                s += x % 10
                x //= 10
            return s

        n = len(nums)
        keyed = [(digit_sum(x), x) for x in nums]
        keyed.sort()

        rank = {val: idx for idx, (_, val) in enumerate(keyed)}
        home = [rank[x] for x in nums]

        swaps = 0
        for i in range(n):
            while home[i] != i:
                j = home[i]
                home[i], home[j] = home[j], home[i]
                swaps += 1
        return swaps
