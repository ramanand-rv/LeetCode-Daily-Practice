impl Solution {
    pub fn path_existence_queries(n: i32, nums: Vec<i32>, max_diff: i32, queries: Vec<Vec<i32>>) -> Vec<bool> {
        let n = n as usize;
        let mut cmp = vec![0; n];
        
        for i in 1..n {
            cmp[i] = cmp[i - 1] + if (nums[i] - nums[i - 1]).abs() > max_diff { 1 } else { 0 };
        }
        
        let mut results = Vec::with_capacity(queries.len());
        for q in &queries {
            let l = q[0] as usize;
            let r = q[1] as usize;
            results.push(cmp[l] == cmp[r]);
        }
        
        results
    }
}