class Solution:
    def validSequence(self, s: str, t: str) -> List[int]:
        n, m = len(s), len(t)
        dp = [0] * (n + 1)
        j = m - 1
        for i in range(n - 1, -1, -1):
            if j >= 0 and s[i] == t[j]:
                dp[i] = dp[i + 1] + 1
                j -= 1
            else:
                dp[i] = dp[i + 1]

        ans = []
        j = 0
        mismatch_used = True

        for i in range(n):
            if j == m:
                break
            rem = m - j - 1
            if s[i] == t[j]:
                ans.append(i)
                j += 1
            elif mismatch_used and dp[i + 1] >= rem:
                ans.append(i)
                j += 1
                mismatch_used = False

        return ans if j == m else []