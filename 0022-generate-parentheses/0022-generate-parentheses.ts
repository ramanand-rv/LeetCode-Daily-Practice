const dp: number[][] = Array.from({ length: 9 }, () => []);

function computeDP(): void {
    if (dp[0].length > 0) return;
    dp[0] = [0];
    for (let i = 1; i <= 8; i++) {
        for (let j = 1; j <= i; j++) {
            for (const x of dp[j - 1]) {
                for (const y of dp[i - j]) {
                    const z = (y << (2 * j)) | (1 << (2 * j - 1)) | (x << 1);
                    dp[i].push(z);
                }
            }
        }
    }
}

function toStr(x: number, n: number): string {
    const len = n << 1;
    let ans = '';
    for (let i = 0; i < len; i++) {
        if (x === 0) {
            ans += '(';
        } else {
            ans += (x & 1) ? ')' : '(';
            x >>= 1;
        }
    }
    return ans;
}

function generateParenthesis(n: number): string[] {
    computeDP();
    return dp[n].map(x => toStr(x, n));
}