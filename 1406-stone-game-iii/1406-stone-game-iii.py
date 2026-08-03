class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        dp = [0] * 4  # circular buffer

        for i in range(n - 1, -1, -1):
            idx = i % 4

            # take 1
            best = stoneValue[i] - dp[(i + 1) % 4]

            # take 2
            if i + 1 < n:
                best = max(best, stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) % 4])

            # take 3
            if i + 2 < n:
                best = max(best, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[(i + 3) % 4])

            dp[idx] = best

        diff = dp[0]
        return "Alice" if diff > 0 else "Bob" if diff < 0 else "Tie"