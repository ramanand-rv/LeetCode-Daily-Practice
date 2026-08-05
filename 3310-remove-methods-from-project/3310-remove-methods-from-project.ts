function remainingMethods(n: number, k: number, invocations: number[][]): number[] {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [u, v] of invocations) g[u].push(v);

    const vis = new Array(n).fill(0);
    const q: number[] = [k];
    vis[k] = 1;
    while (q.length) {
        const u = q.shift()!;
        for (const v of g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    for (const [u, v] of invocations) {
        if (!vis[u] && vis[v]) {
            return Array.from({ length: n }, (_, i) => i);
        }
    }

    const ans: number[] = [];
    for (let i = 0; i < n; i++) {
        if (!vis[i]) ans.push(i);
    }
    return ans;
}