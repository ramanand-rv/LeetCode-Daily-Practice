function numOfSubarrays(arr: number[]): number {
    const MOD = 1_000_000_007;
    let even = 1, odd = 0, ans = 0;
    let parity = 0;

    for (const x of arr) {
        parity = (parity + x) & 1;   // 0 or 1
        if (parity === 1) {
            ans = (ans + even) % MOD;
            odd++;
        } else {
            ans = (ans + odd) % MOD;
            even++;
        }
    }
    return ans;
}