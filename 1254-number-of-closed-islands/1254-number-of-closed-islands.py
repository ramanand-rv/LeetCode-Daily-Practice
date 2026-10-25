class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        def closed(i: int, j: int) -> bool:
            if i < 0 or i >= m or j < 0 or j >= n:
                return False
            if grid[i][j] == 1:
                return True

            grid[i][j] = 1  # mark visited

            a = closed(i + 1, j)
            b = closed(i - 1, j)
            c = closed(i, j + 1)
            d = closed(i, j - 1)

            return a and b and c and d  # all four already called

        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and closed(i, j):
                    count += 1
        return count