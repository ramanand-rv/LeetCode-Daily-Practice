function validSequence(s: string, t: string): number[] {
    const n = s.length, m = t.length;
    const dp: number[] = new Array(n + 1).fill(0);
    let j = m - 1;
    for (let i = n - 1; i >= 0; i--) {
        if (j >= 0 && s[i] === t[j]) {
            dp[i] = dp[i + 1] + 1;
            j--;
        } else {
            dp[i] = dp[i + 1];
        }
    }

    const ans: number[] = [];
    j = 0;
    let mismatchUsed = true;

    for (let i = 0; i < n && j < m; i++) {
        const rem = m - j - 1;
        if (s[i] === t[j]) {
            ans.push(i);
            j++;
        } else if (mismatchUsed && dp[i + 1] >= rem) {
            ans.push(i);
            j++;
            mismatchUsed = false;
        }
    }

    return j === m ? ans : [];
}