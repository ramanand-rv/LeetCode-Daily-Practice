function smallestPalindrome(s: string, k: number): string {
    const n = s.length;
    const half = n >> 1;
    const freq = new Array(26).fill(0);
    for (const ch of s) freq[ch.charCodeAt(0) - 97]++;

    const res: string[] = new Array(n).fill(' ');
    // middle character
    for (let i = 0; i < 26; i++) {
        if (freq[i] & 1) res[n >> 1] = String.fromCharCode(97 + i);
        freq[i] >>= 1;
    }

    const nCr = (n: number, r: number, limit: number): number => {
        r = Math.min(r, n - r);
        let ans = 1;
        for (let i = 1; i <= r; i++) {
            ans = ans * (n - i + 1) / i;
            if (ans > limit) return limit + 1;
        }
        return ans;
    };

    const ways = (rem: number, f: number[], limit: number): number => {
        let total = 1;
        for (let i = 0; i < 26; i++) {
            total *= nCr(rem, f[i], limit);
            if (total > limit) return limit + 1;
            rem -= f[i];
        }
        return total;
    };

    const total = ways(half, freq, k);
    if (total < k) return "";

    for (let idx = 0; idx < half; idx++) {
        for (let i = 0; i < 26; i++) {
            if (freq[i] === 0) continue;
            freq[i]--;
            const possible = ways(half - idx - 1, freq, k);
            if (possible >= k) {
                res[idx] = String.fromCharCode(97 + i);
                break;
            } else {
                k -= possible;
                freq[i]++;
            }
        }
    }

    for (let i = 0; i < half; i++) {
        res[n - 1 - i] = res[i];
    }
    return res.join('');
}