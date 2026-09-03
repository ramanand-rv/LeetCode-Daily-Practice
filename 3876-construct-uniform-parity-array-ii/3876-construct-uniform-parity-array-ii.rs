impl Solution {
    pub fn uniform_array(nums1: Vec<i32>) -> bool {
        let mut mn = i32::MAX;
        let mut odd_cnt = 0;

        for &x in nums1.iter() {   // iterate over reference to avoid moving
            if x < mn { mn = x; }
            if x % 2 == 1 { odd_cnt += 1; }
        }

        (mn % 2 == 1) || (odd_cnt == 0)
    }
}