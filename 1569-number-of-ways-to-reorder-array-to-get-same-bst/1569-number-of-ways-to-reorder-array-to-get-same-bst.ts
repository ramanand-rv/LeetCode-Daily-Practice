function numOfWays(nums: number[]): number {
    const MOD = 1000000007n;
    const n = nums.length;
    const born: bigint[] = new Array(n + 2).fill(-1n);
    for (let i = 0; i < n; i++) {
        born[nums[i]] = BigInt(i);
    }

    let fact = 1n;
    for (let k = 2n; k <= BigInt(n); k++) {
        fact = (fact * k) % MOD;
    }

    let sizes = 1n;
    const stack: number[] = [0];

    for (let v = 1; v <= n + 1; v++) {
        while (born[stack[stack.length - 1]] > born[v]) {
            const u = stack.pop()!;
            const below = stack[stack.length - 1];
            const size = BigInt(v - below - 1);
            sizes = (sizes * size) % MOD;
        }
        stack.push(v);
    }

    const power = (base: bigint, exp: bigint): bigint => {
        let res = 1n;
        base %= MOD;
        while (exp > 0n) {
            if (exp & 1n) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1n;
        }
        return res;
    };

    const inv = power(sizes, MOD - 2n);
    const ans = (fact * inv - 1n + MOD) % MOD;
    return Number(ans);
}