function maxDepth(s: string): number {
    let ans = 0, depth = 0;
    for (const ch of s) {
        depth += (ch === '(' ? 1 : 0) - (ch === ')' ? 1 : 0);
        ans = Math.max(ans, depth);
    }
    return ans;
}