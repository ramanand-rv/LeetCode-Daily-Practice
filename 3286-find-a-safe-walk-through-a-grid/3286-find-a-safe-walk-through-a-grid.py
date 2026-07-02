from collections import deque
from typing import List

class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        m, n = len(grid), len(grid[0])
        INF = 10**9
        
        # Distance array
        dist = [[INF] * n for _ in range(m)]
        dist[0][0] = grid[0][0]
        
        # 0-1 BFS
        dq = deque([(0, 0)])
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        while dq:
            x, y = dq.popleft()
            
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                
                if 0 <= nx < m and 0 <= ny < n:
                    w = grid[nx][ny]
                    
                    if dist[x][y] + w < dist[nx][ny]:
                        dist[nx][ny] = dist[x][y] + w
                        
                        if w == 0:
                            dq.appendleft((nx, ny))  # 0-cost → front
                        else:
                            dq.append((nx, ny))      # 1-cost → back
        
        return dist[m - 1][n - 1] < health