function predictTheWinner(nums: number[]): boolean {
    const n = nums.length;
    if ((n & 1) === 0) return true; // even length

    const dp: number[] = new Array(n);

    for (let i = n - 1; i >= 0; i--) {
        dp[i] = nums[i];
        
        for (let j = i + 1; j < n; j++) {
            dp[j] = Math.max(nums[i] - dp[j], nums[j] - dp[j - 1]);
        }
    }
    return dp[n - 1] >= 0;
}