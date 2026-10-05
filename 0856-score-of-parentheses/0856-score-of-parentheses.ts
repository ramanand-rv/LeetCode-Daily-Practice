function scoreOfParentheses(s: string): number {
    function F(i: number, j: number): number {
        let ans = 0, bal = 0;
        for (let k = i; k < j; k++) {
            bal += s[k] === '(' ? 1 : -1;
            if (bal === 0) {
                if (k - i === 1) {
                    ans += 1;
                } else {
                    ans += 2 * F(i + 1, k);
                }
                i = k + 1;
            }
        }
        return ans;
    }
    return F(0, s.length);
}