function maxSubarrayLength(nums: number[], k: number): number {
    const freq = new Map<number, number>();
    let i = 0, res = 0;
    for (let j = 0; j < nums.length; j++) {
        freq.set(nums[j], (freq.get(nums[j]) || 0) + 1);
        while (freq.get(nums[j])! > k) {
            freq.set(nums[i], freq.get(nums[i])! - 1);
            i++;
        }
        res = Math.max(res, j - i + 1);
    }
    return res;
}