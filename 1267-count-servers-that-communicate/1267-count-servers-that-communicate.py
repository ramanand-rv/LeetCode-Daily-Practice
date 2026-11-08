class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])
        row = [0] * m
        col = [0] * n

        # Count servers in each row and column
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    row[i] += 1
                    col[j] += 1

        ans = 0
        # Check if each server shares its row or column with another
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and (row[i] > 1 or col[j] > 1):
                    ans += 1

        return ans
