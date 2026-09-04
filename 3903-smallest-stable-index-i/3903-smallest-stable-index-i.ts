function firstStableIndex(nums: number[], k: number): number {
    const n = nums.length;
    const suf: number[] = new Array(n);

    // Precompute suffix minimums
    suf[n - 1] = nums[n - 1];
    for (let i = n - 2; i >= 0; i--) {
        suf[i] = Math.min(suf[i + 1], nums[i]);
    }

    // Scan forward, track prefix maximum
    let maxSoFar = -Infinity;
    for (let i = 0; i < n; i++) {
        maxSoFar = Math.max(maxSoFar, nums[i]);
        if (maxSoFar - suf[i] <= k) {
            return i;
        }
    }
    return -1;
};