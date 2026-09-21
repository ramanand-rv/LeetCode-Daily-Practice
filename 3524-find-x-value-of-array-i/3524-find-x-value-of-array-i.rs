impl Solution {
    pub fn result_array(nums: Vec<i32>, k: i32) -> Vec<i64> {
        let n = nums.len();
        let k = k as usize;
        let arr: Vec<usize> = nums.iter().map(|&x| (x as usize) % k).collect();
        let mut res = vec![0i64; k];

        for req in 0..k {
            // dp[i][prevProd] = count
            let mut dp = vec![vec![-1i64; k + 1]; n];

            fn solve(
                i: usize,
                prev_prod: usize,
                req: usize,
                k: usize,
                arr: &Vec<usize>,
                dp: &mut Vec<Vec<i64>>,
            ) -> i64 {
                if i >= arr.len() {
                    return 0;
                }
                if dp[i][prev_prod] != -1 {
                    return dp[i][prev_prod];
                }

                let mut skip = 0i64;
                let mut take = 0i64;

                if prev_prod == k {
                    skip = solve(i + 1, k, req, k, arr, dp);
                }

                let cur_prod = if prev_prod == k {
                    arr[i]
                } else {
                    (prev_prod * arr[i]) % k
                };

                if cur_prod == req {
                    take += 1;
                }
                take += solve(i + 1, cur_prod, req, k, arr, dp);

                let total = skip + take;
                dp[i][prev_prod] = total;
                total
            }

            res[req] = solve(0, k, req, k, &arr, &mut dp);
        }

        res
    }
}