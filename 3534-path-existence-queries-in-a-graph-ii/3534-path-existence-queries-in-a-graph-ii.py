from typing import List

class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[int]:
        # Step 1: Sort by value with original indices
        sorted_nums = sorted([(nums[i], i) for i in range(n)])
        
        # Step 2: Map original index → sorted position
        point = {}
        for i, (val, idx) in enumerate(sorted_nums):
            point[idx] = i
        
        # Step 3: Find upward reach
        up = [0] * (n + 1)
        j = 0
        for i in range(n):
            while j + 1 < n and sorted_nums[j + 1][0] - sorted_nums[i][0] <= maxDiff:
                j += 1
            if j < i:
                j = i
            up[i] = j
        up[n] = n
        
        # Step 4: Build binary lifting table
        k = int(math.ceil(math.log2(n))) + 1
        dp = [[0] * (k + 1) for _ in range(n + 1)]
        
        for i in range(n + 1):
            dp[i][0] = up[i]
        
        for j in range(1, k):
            for i in range(n + 1):
                dp[i][j] = dp[dp[i][j - 1]][j - 1]
        
        # Step 5: Process queries
        results = []
        
        for u, v in queries:
            if u == v:
                results.append(0)
                continue
            
            st = min(point[u], point[v])
            en = max(point[u], point[v])
            
            if up[st] == st:
                results.append(-1)
                continue
            
            node = st
            steps = 0
            
            for i in range(k - 1, -1, -1):
                if dp[node][i] < en:
                    node = dp[node][i]
                    steps += 1 << i
            
            if up[node] < en:
                results.append(-1)
            else:
                results.append(steps + 1)
        
        return results