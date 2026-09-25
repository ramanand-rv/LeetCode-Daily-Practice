class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        ans = set()

        def dfs(s: str):
            r = s.find('}')
            if r == -1:
                ans.add(s)
                return
            l = s.rfind('{', 0, r)
            left = s[:l]
            right = s[r + 1:]
            inside = s[l + 1:r]
            for part in inside.split(','):
                dfs(left + part + right)

        dfs(expression)
        return sorted(ans)