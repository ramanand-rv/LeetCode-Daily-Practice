impl Solution {
    pub fn predict_the_winner(nums: Vec<i32>) -> bool {
        let n = nums.len();
        if n % 2 == 0 {
            return true;
        }

        let mut dp = vec![0; n];
        for i in (0..n).rev() {
            dp[i] = nums[i];
            for j in i + 1..n {
                dp[j] = (nums[i] - dp[j]).max(nums[j] - dp[j - 1]);
            }
        }
        dp[n - 1] >= 0
    }
}