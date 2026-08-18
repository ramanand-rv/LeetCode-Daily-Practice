use std::collections::HashMap;

impl Solution {
    pub fn largest_integer(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut freq = HashMap::new();
        for &x in &nums {
            *freq.entry(x).or_insert(0) += 1;
        }

        if k as usize == n {
            return *nums.iter().max().unwrap();
        }

        if k == 1 {
            let mut ans = -1;
            for &x in &nums {
                if freq[&x] == 1 {
                    ans = ans.max(x);
                }
            }
            return ans;
        }

        let first = nums[0];
        let last = nums[n - 1];

        if first == last {
            return -1;
        }

        let first_valid = freq[&first] == 1;
        let last_valid = freq[&last] == 1;

        if first_valid && last_valid {
            return first.max(last);
        }
        if first_valid {
            return first;
        }
        if last_valid {
            return last;
        }
        -1
    }
}