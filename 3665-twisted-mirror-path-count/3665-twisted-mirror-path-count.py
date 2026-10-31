class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        MOD = 10**9 + 7
        n = len(grid[0])

        down = [0] * n
        down[0] = 1

        for row in grid:
            right = 0
            for j, mirror in enumerate(row):
                if mirror:
                    right, down[j] = down[j], right
                else:
                    right = down[j] = (right + down[j]) % MOD

        return down[-1]