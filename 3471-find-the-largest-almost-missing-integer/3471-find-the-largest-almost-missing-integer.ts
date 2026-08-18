function largestInteger(nums: number[], k: number): number {
    const n = nums.length;
    const freq = new Map<number, number>();
    for (const x of nums) freq.set(x, (freq.get(x) || 0) + 1);

    if (k === n) return Math.max(...nums);

    if (k === 1) {
        let ans = -1;
        for (const x of nums) {
            if (freq.get(x) === 1) ans = Math.max(ans, x);
        }
        return ans;
    }

    const first = nums[0];
    const last = nums[n - 1];

    if (first === last) return -1;

    const firstValid = (freq.get(first) === 1);
    const lastValid  = (freq.get(last) === 1);

    if (firstValid && lastValid) return Math.max(first, last);
    if (firstValid) return first;
    if (lastValid) return last;
    return -1;
}