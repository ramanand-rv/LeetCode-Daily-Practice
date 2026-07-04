import heapq
from typing import List

class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        n = len(online)
        adj = [[] for _ in range(n)]
        low, high = float('inf'), -float('inf')
        
        for u, v, cst in edges:
            adj[u].append((v, cst))
            low = min(low, cst)
            high = max(high, cst)
        
        if not edges:
            return 0 if n == 1 else -1
        
        def can_reach(limit: int) -> bool:
            INF = 10**18
            dist = [INF] * n
            dist[0] = 0
            pq = [(0, 0)]  # (cost, node)
            
            while pq:
                cur_cost, node = heapq.heappop(pq)
                if cur_cost > dist[node]:
                    continue
                if node == n - 1:
                    break
                for nxt_node, weight in adj[node]:
                    if weight < limit:
                        continue
                    if nxt_node != n - 1 and not online[nxt_node]:
                        continue
                    new_cost = cur_cost + weight
                    if new_cost < dist[nxt_node]:
                        dist[nxt_node] = new_cost
                        heapq.heappush(pq, (new_cost, nxt_node))
            
            return dist[n - 1] <= k
        
        res = -1
        lo, hi = low, high
        while lo <= hi:
            mid = (lo + hi) // 2
            if can_reach(mid):
                res = mid
                lo = mid + 1
            else:
                hi = mid - 1
        
        return res