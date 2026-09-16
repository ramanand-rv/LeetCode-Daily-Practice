class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        MOD = 10**9 + 7
        dp = [[0] * (k + 1) for _ in range(n)]

        for i in range(n):
            dp[i][0] = 1

        for j in range(1, k + 1):
            running = 0
            for i in range(1, n):
                running = (running + dp[i - 1][j - 1]) % MOD
                dp[i][j] = (dp[i - 1][j] + running) % MOD

        return dp[n - 1][k]
