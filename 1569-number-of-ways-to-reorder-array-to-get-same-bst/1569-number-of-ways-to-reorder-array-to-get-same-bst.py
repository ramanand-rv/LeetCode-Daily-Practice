class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        born = [-1] * (n + 2)
        for i, x in enumerate(nums):
            born[x] = i

        fact = 1
        for k in range(2, n + 1):
            fact = fact * k % MOD

        sizes = 1
        stack = [0]

        for v in range(1, n + 2):
            while born[stack[-1]] > born[v]:
                stack.pop()
                below = stack[-1]
                sizes = sizes * (v - below - 1) % MOD
            stack.append(v)

        inv = pow(sizes, MOD - 2, MOD)
        return (fact * inv - 1) % MOD
