function generateParenthesis(n: number): string[] {
    const ans: string[] = [];

    function dfs(lp: number, rp: number, level: number, current: string) {
        if (lp === n && rp === n && level === 0) {
            ans.push(current);
            return;
        }
        if (lp < n) {
            dfs(lp + 1, rp, level + 1, current + '(');
        }
        if (rp < n && level >= 1) {
            dfs(lp, rp + 1, level - 1, current + ')');
        }
    }

    dfs(1, 0, 1, '(');
    return ans;
}