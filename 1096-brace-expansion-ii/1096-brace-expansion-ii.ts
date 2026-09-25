function braceExpansionII(expression: string): string[] {
    const ans = new Set<string>();

    function dfs(s: string): void {
        const r = s.indexOf('}');
        if (r === -1) {
            ans.add(s);
            return;
        }
        const l = s.lastIndexOf('{', r);
        const left = s.substring(0, l);
        const right = s.substring(r + 1);
        const inside = s.substring(l + 1, r);
        for (const part of inside.split(',')) {
            dfs(left + part + right);
        }
    }

    dfs(expression);
    return Array.from(ans).sort();
}