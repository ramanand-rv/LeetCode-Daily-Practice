use std::collections::HashMap;

impl Solution {
    pub fn min_swaps(nums: Vec<i32>) -> i32 {
        fn digit_sum(mut x: i32) -> i32 {
            let mut s = 0;
            while x > 0 {
                s += x % 10;
                x /= 10;
            }
            s
        }

        let n = nums.len();
        let mut keyed: Vec<(i32, i32)> = nums.iter().map(|&x| (digit_sum(x), x)).collect();
        keyed.sort();

        let mut rank = HashMap::new();
        for (idx, &(_, val)) in keyed.iter().enumerate() {
            rank.insert(val, idx);
        }

        let mut home: Vec<usize> = nums.iter().map(|&x| rank[&x]).collect();

        let mut swaps = 0;
        for i in 0..n {
            while home[i] != i {
                let j = home[i];
                home.swap(i, j);
                swaps += 1;
            }
        }
        swaps
    }
}