function findSubtreeSizes(p: number[], s: string): number[] {
    const n = p.length;
    const adj: number[][] = Array.from({ length: n }, () => []);
    const tree: number[][] = Array.from({ length: n }, () => []);

    // Build original tree
    for (let i = 1; i < n; i++) adj[p[i]].push(i);

    const last: number[] = new Array(26).fill(-1);

    // DFS to update parents
    const dfs = (u: number) => {
        const c = s.charCodeAt(u) - 97;
        const old = last[c];
        if (u !== 0 && old !== -1) p[u] = old;
        last[c] = u;
        for (const v of adj[u]) dfs(v);
        last[c] = old;
    };
    dfs(0);

    // Build new tree
    for (let i = 1; i < n; i++) tree[p[i]].push(i);

    const ans: number[] = new Array(n).fill(0);

    // Calculate subtree sizes
    const calc = (u: number): number => {
        ans[u] = 1;
        for (const v of tree[u]) ans[u] += calc(v);
        return ans[u];
    };
    calc(0);

    return ans;
}