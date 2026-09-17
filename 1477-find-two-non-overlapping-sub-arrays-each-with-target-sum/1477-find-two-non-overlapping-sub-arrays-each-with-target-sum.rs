impl Solution {
    pub fn min_sum_of_lengths(arr: Vec<i32>, target: i32) -> i32 {
        let n = arr.len();
        let mut res = (n + 1) as i32;
        let mut sum = 0;
        let mut i = 0;

        // dp[j] = min length of a valid subarray ending before index j
        let mut dp = vec![n as i32; n + 1];

        for j in 0..n {
            sum += arr[j];

            while sum > target {
                sum -= arr[i];
                i += 1;
            }

            dp[j + 1] = dp[j];

            if sum == target {
                let len = (j - i + 1) as i32;
                // dp[i] is min length before index i (non‑overlapping)
                res = res.min(len + dp[i]);
                dp[j + 1] = dp[j].min(len);
            }
        }

        if res == (n + 1) as i32 { -1 } else { res }
    }
}