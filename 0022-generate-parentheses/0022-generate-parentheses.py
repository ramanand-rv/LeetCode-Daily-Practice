class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []

        def dfs(lp: int, rp: int, level: int, current: str):
            if lp == n and rp == n and level == 0:
                ans.append(current)
                return
            if lp < n:
                dfs(lp + 1, rp, level + 1, current + '(')
            if rp < n and level >= 1:
                dfs(lp, rp + 1, level - 1, current + ')')

        dfs(1, 0, 1, '(')
        return ans