class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        n = len(arr)
        res = n + 1
        total = 0
        i = 0

        # dp[j] = min length of a valid subarray ending before index j
        dp = [n] * (n + 1)

        for j in range(n):
            total += arr[j]

            while total > target:
                total -= arr[i]
                i += 1

            dp[j + 1] = dp[j]

            if total == target:
                length = j - i + 1
                # dp[i] is min length before index i → non‑overlapping
                res = min(res, length + dp[i])
                dp[j + 1] = min(dp[j], length)

        return -1 if res == n + 1 else res
