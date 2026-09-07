function distinctSubseqII(s: string): number {
    const MOD = 1_000_000_007;
    const endWith = new Array(26).fill(0);
    let total = 0;

    for (const ch of s) {
        const idx = ch.charCodeAt(0) - 97;
        const newSubseqs = (1 + total - endWith[idx] + MOD) % MOD;
        total = (total + newSubseqs) % MOD;
        endWith[idx] = (endWith[idx] + newSubseqs) % MOD;
    }
    return total;
};