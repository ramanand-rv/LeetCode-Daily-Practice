impl Solution {
    pub fn unique_xor_triplets(nums: Vec<i32>) -> i32 {
        let n = nums.len() as i32;

        if n < 3 { return n; }

        let mut ans = 1;

        while ans <= n { ans <<= 1; }
        
        ans
    }
}