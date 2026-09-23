function minOperations(nums: number[], x: number): number {
    const n = nums.length;
    const total = nums.reduce((a, b) => a + b, 0);
    const target = total - x;

    if (target < 0) return -1;
    if (target === 0) return n;

    let left = 0;
    let sum = 0;
    let longest = -1;

    for (let right = 0; right < n; right++) {
        sum += nums[right];
        while (left <= right && sum > target) {
            sum -= nums[left++];
        }
        if (sum === target) {
            longest = Math.max(longest, right - left + 1);
        }
    }

    return longest === -1 ? -1 : n - longest;
}