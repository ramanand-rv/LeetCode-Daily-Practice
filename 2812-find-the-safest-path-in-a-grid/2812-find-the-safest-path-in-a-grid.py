from collections import deque
from typing import List

class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        # Step 1: Multi-Source BFS to compute distances
        dist = [[float('inf')] * n for _ in range(n)]
        q = deque()
        
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    dist[i][j] = 0
                    q.append((i, j))
        
        while q:
            r, c = q.popleft()
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and dist[nr][nc] == float('inf'):
                    dist[nr][nc] = dist[r][c] + 1
                    q.append((nr, nc))
        
        # Step 2: Binary Search
        def can_reach(limit: int) -> bool:
            if dist[0][0] < limit:
                return False
            
            vis = [[False] * n for _ in range(n)]
            q = deque([(0, 0)])
            vis[0][0] = True
            
            while q:
                r, c = q.popleft()
                if r == n - 1 and c == n - 1:
                    return True
                
                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < n and 0 <= nc < n and not vis[nr][nc] and dist[nr][nc] >= limit:
                        vis[nr][nc] = True
                        q.append((nr, nc))
            
            return False
        
        low, high, ans = 0, 2 * n, 0
        while low <= high:
            mid = (low + high) // 2
            if can_reach(mid):
                ans = mid
                low = mid + 1
            else:
                high = mid - 1
        
        return ans