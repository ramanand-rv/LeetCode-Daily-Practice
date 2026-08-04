impl Solution {
    pub fn find_missing_elements(nums: Vec<i32>) -> Vec<i32> {
        let mut present = [false; 101];
        let mut min_val = i32::MAX;
        let mut max_val = i32::MIN;

        for &ele in &nums {
            min_val = min_val.min(ele);
            max_val = max_val.max(ele);
            present[ele as usize] = true;
        }

        let mut res = Vec::new();
        for i in min_val..=max_val {
            if !present[i as usize] {
                res.push(i);
            }
        }
        res
    }
}