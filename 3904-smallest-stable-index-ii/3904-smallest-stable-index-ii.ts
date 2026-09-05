function firstStableIndex(nums: number[], k: number): number {
    let maxSoFar = -Infinity;
    let cand = 0;
    let cMax = 0;
    const n = nums.length;

    for (let i = 0; i < n; i++) {
        maxSoFar = Math.max(maxSoFar, nums[i]);

        if (i === cand) cMax = maxSoFar;

        if (nums[i] < cMax - k) {
            cand = i + 1;
        }
    }

    return cand < n ? cand : -1;
};