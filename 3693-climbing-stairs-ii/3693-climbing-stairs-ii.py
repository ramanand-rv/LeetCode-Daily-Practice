class Solution:
    def climbStairs(self, n: int, costs: list[int]) -> int:
        # dp[j] stores the minimum cost to reach step j
        dp = [float('inf')] * (n + 1)
        dp[0] = 0 # Starting at step 0 costs nothing

        for j in range(1, n + 1):
            # Try jumping from the previous 1, 2, or 3 steps
            for k in range(1, 4):
                i = j - k # The step we are jumping from
                if i >= 0:
                    jump_cost = (j - i) ** 2 # Squared jump distance
                    # Update min cost
                    dp[j] = min(dp[j], dp[i] + costs[j - 1] + jump_cost)

        return dp[n]