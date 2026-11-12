function longestMonotonicSubarray(nums: number[]): number {
    let best = 1;
    let up = 1;
    let down = 1;

    for (let i = 1; i < nums.length; i++) {
        // Extend increasing streak if current > previous, else reset to 1
        up = nums[i - 1] < nums[i] ? up + 1 : 1;

        // Extend decreasing streak if current < previous, else reset to 1
        down = nums[i - 1] > nums[i] ? down + 1 : 1;

        // Update the global maximum streak length
        best = Math.max(best, up, down);
    }

    return best;
}