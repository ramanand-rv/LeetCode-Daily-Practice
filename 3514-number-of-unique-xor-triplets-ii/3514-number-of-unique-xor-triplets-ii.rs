impl Solution {
    pub fn unique_xor_triplets(nums: Vec<i32>) -> i32 {
        const MAX: usize = 2048;
        let mut pair_xor = [0; MAX];
        let mut triple_xor = [0; MAX];

        let n = nums.len();

        // All pair XORs
        for i in 0..n {
            for j in i..n {
                pair_xor[(nums[i] ^ nums[j]) as usize] = 1;
            }
        }

        // All triplet XORs
        for &x in &nums {
            for j in 0..MAX {
                if pair_xor[j] == 1 {
                    triple_xor[(j ^ (x as usize))] = 1;
                }
            }
        }

        // Count distinct
        triple_xor.iter().sum()
    }
}