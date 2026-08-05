from collections import deque
from typing import List

class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        g = [[] for _ in range(n)]
        for u, v in invocations:
            g[u].append(v)

        vis = [0] * n
        q = deque([k])
        vis[k] = 1
        while q:
            u = q.popleft()
            for v in g[u]:
                if not vis[v]:
                    vis[v] = 1
                    q.append(v)

        # Check for external invocations
        for u, v in invocations:
            if not vis[u] and vis[v]:
                return list(range(n))

        return [i for i in range(n) if not vis[i]]