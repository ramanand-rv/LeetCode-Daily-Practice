function maxSum(nums: number[], k: number): number {
    const MOD = 1_000_000_007;
    const bitCount = new Array(32).fill(0);

    for (const num of nums) {
        for (let b = 0; b < 32; b++) {
            if (num & (1 << b)) bitCount[b]++;
        }
    }

    let ans = 0n;
    const MODn = BigInt(MOD);

    while (k--) {
        let cur = 0n;
        for (let b = 0; b < 32; b++) {
            if (bitCount[b] > 0) {
                bitCount[b]--;
                cur |= (1n << BigInt(b));
            }
        }
        ans = (ans + cur * cur) % MODn;
    }

    return Number(ans);
}