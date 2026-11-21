class Solution:
    def findSubtreeSizes(self, p: list[int], s: str) -> list[int]:
        n = len(p)
        adj = [[] for _ in range(n)]
        tree = [[] for _ in range(n)]
        
        # Build original tree
        for i in range(1, n):
            adj[p[i]].append(i)
        
        last = [-1] * 26
        
        # DFS to update parents
        def dfs(u: int):
            c = ord(s[u]) - ord('a')
            old = last[c]
            if u != 0 and old != -1:
                p[u] = old
            last[c] = u
            for v in adj[u]:
                dfs(v)
            last[c] = old
        
        dfs(0)
        
        # Build new tree
        for i in range(1, n):
            tree[p[i]].append(i)
        
        ans = [0] * n
        
        # Calculate subtree sizes
        def calc(u: int) -> int:
            ans[u] = 1
            for v in tree[u]:
                ans[u] += calc(v)
            return ans[u]
        
        calc(0)
        return ans