from collections import deque
from typing import List

class Solution:
    def minMoves(self, classroom: List[str], energy: int) -> int:
        m, n = len(classroom), len(classroom[0])
        sr = sc = -1
        cnt = 0
        id_map = [[-1]*n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if classroom[i][j] == 'S':
                    sr, sc = i, j
                elif classroom[i][j] == 'L':
                    id_map[i][j] = cnt
                    cnt += 1

        masks = 1 << cnt
        full_mask = masks - 1
        best = [[[-1]*masks for _ in range(n)] for _ in range(m)]

        q = deque()
        q.append((sr, sc, 0, energy, 0))  # r, c, mask, en, dist
        best[sr][sc][0] = energy

        dirs = [(-1,0),(1,0),(0,-1),(0,1)]

        while q:
            r, c, mask, en, dist = q.popleft()
            if mask == full_mask:
                return dist
            if en == 0:
                continue

            for dr, dc in dirs:
                nr, nc = r+dr, c+dc
                if nr < 0 or nr >= m or nc < 0 or nc >= n:
                    continue
                if classroom[nr][nc] == 'X':
                    continue

                new_en = en - 1
                new_mask = mask

                if classroom[nr][nc] == 'L':
                    new_mask |= (1 << id_map[nr][nc])
                if classroom[nr][nc] == 'R':
                    new_en = energy

                if best[nr][nc][new_mask] >= new_en:
                    continue

                best[nr][nc][new_mask] = new_en
                q.append((nr, nc, new_mask, new_en, dist+1))

        return -1