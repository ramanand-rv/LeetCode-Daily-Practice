impl Solution {
    pub fn sort_permutation(nums: Vec<i32>) -> i32 {
        let mut k: i32 = -1; // all bits set
        for (i, &x) in nums.iter().enumerate() {
            if x != i as i32 {
                k &= x;
                if k == 0 {
                    return 0;
                }
            }
        }
        k.max(0)
    }
}