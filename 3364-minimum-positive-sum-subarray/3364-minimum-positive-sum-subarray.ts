function minimumSumSubarray(nums: number[], l: number, r: number): number {
    const n = nums.length;
    let ans = Infinity;

    // Try every possible starting index
    for (let i = 0; i < n; i++) {
        let sum = 0;

        // Extend the subarray to the right
        for (let j = i; j < n; j++) {
            sum += nums[j];
            const len = j - i + 1;

            // Check if length is within bounds and sum is positive
            if (len >= l && len <= r && sum > 0) {
                ans = Math.min(ans, sum);
            }
        }
    }

    // Return -1 if no valid subarray was found
    return ans === Infinity ? -1 : ans;
}