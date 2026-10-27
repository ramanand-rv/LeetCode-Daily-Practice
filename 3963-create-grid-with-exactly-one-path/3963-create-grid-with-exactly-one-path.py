class Solution:
    def createGrid(self, m: int, n: int) -> List[str]:
        grid = [["#"] * n for _ in range(m)]
        r = c = 0
        grid[0][0] = "."

        while r < m - 1 or c < n - 1:
            down_err = (
                abs((r + 1) * (n - 1) - c * (m - 1)) if r < m - 1 else float("inf")
            )
            right_err = (
                abs(r * (n - 1) - (c + 1) * (m - 1)) if c < n - 1 else float("inf")
            )

            if r < m - 1 and down_err <= right_err:
                r += 1
            else:
                c += 1

            grid[r][c] = "."

        return ["".join(row) for row in grid]
