from typing import List


class Solution:
    def maximumWeight(self, intervals: List[List[int]]) -> List[int]:
        # Deduplicate: keep smallest original index for identical intervals
        d = {}
        for i, (l, r, w) in enumerate(intervals):
            key = (l, r, w)
            if key not in d:
                d[key] = i
        arr = [(l, r, w, idx) for (l, r, w), idx in d.items()]
        arr.sort()
        n = len(arr)

        # nextIndex[i] = first interval j > i with left > right_i
        nextIndex = [n] * n
        for i in range(n):
            r = arr[i][1]
            lo, hi = i + 1, n
            while lo < hi:
                mid = (lo + hi) // 2
                if arr[mid][0] > r:
                    hi = mid
                else:
                    lo = mid + 1
            nextIndex[i] = lo

        # dp[i][k] = (neg_weight, tuple of indices)
        dp = [[(0, ()) for _ in range(5)] for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            _, _, w, idx = arr[i]
            for k in range(1, 5):
                skip = dp[i + 1][k]
                take_base = dp[nextIndex[i]][k - 1]
                new_indices = tuple(sorted(take_base[1] + (idx,)))
                take = (take_base[0] - w, new_indices)
                dp[i][k] = min(skip, take)
        return list(dp[0][4][1])
