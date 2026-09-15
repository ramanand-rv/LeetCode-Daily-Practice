function maxPalindromes(s: string, k: number): number {
    let n = s.length, ans = 0, end = -1;
    for (let i = 0; i < n; i++) {
        for (let l of [i - 1, i]) {
            let r = i;
            while (l >= 0 && r < n && s[l] === s[r]) {
                if (r - l + 1 >= k && l > end) {
                    ans++;
                    end = r;
                    break;
                }
                l--; r++;
            }
        }
    }
    return ans;
}