function sumCounts(nums: number[]): number {
    const MOD = 1_000_000_007;
    const n = nums.length;
    const cnt = new Array(n + 1).fill(0);
    const tot = new Array(n + 1).fill(0);
    const last = new Map<number, number>();
    let ans = 0;

    for (let r = 0; r < n; r++) {
        const x = nums[r];
        const p = last.has(x) ? last.get(x)! : -1;

        let c = 0, s = 0;
        for (let i = n - p - 1; i > 0; i -= i & -i) {
            c += cnt[i];
            s += tot[i];
        }

        const gain = (r - p) * (r - p) - 2 * (s - p * c);
        ans = (ans + (n - r) * gain) % MOD;
        if (ans < 0) ans += MOD;

        for (let i = n - p; i <= n; i += i & -i) {
            cnt[i]++;
            tot[i] += p;
        }
        last.set(x, r);
    }

    return ans;
}