function uniqueXorTriplets(nums: number[]): number {
    const n = nums.length;
    const MAX = 2048;
    const pairXor: number[] = new Array(MAX).fill(0);
    const tripleXor: number[] = new Array(MAX).fill(0);

    // All pair XORs (including i == j)
    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            pairXor[nums[i] ^ nums[j]] = 1;
        }
    }

    // All triplet XORs
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < MAX; j++) {
            if (pairXor[j] === 1) {
                tripleXor[j ^ nums[i]] = 1;
            }
        }
    }

    // Count distinct
    let cnt = 0;
    for (const val of tripleXor) {
        if (val === 1) cnt++;
    }
    return cnt;
}