class Solution:
    def hasValidPath(self, grid: List[List[str]]) -> bool:
        rows = len(grid)
        cols = len(grid[0])

        if grid[0][0] == ")" or grid[rows - 1][cols - 1] == "(":
            return False

        if (rows + cols - 1) % 2 != 0:
            return False

        # memo[row][col][balance] = -1 (unvisited), 0 (false), 1 (true)
        memo = [[[-1] * (rows + cols) for _ in range(cols)] for _ in range(rows)]

        def dfs(row: int, col: int, balance: int) -> bool:
            if grid[row][col] == "(":
                balance += 1
            else:
                balance -= 1

            if balance < 0:
                return False

            if row == rows - 1 and col == cols - 1:
                return balance == 0

            if memo[row][col][balance] != -1:
                return memo[row][col][balance] == 1

            valid = False

            if row + 1 < rows:
                valid = dfs(row + 1, col, balance)

            if not valid and col + 1 < cols:
                valid = dfs(row, col + 1, balance)

            memo[row][col][balance] = 1 if valid else 0
            return valid

        return dfs(0, 0, 0)
