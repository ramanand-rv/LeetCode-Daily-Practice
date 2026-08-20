impl Solution {
    pub fn result_array(nums: Vec<i32>) -> Vec<i32> {
        let mut arr1 = vec![nums[0]];
        let mut arr2 = vec![nums[1]];

        for &x in &nums[2..] {
            if arr1.last().unwrap() > arr2.last().unwrap() {
                arr1.push(x);
            } else {
                arr2.push(x);
            }
        }

        arr1.extend(arr2);
        arr1
    }
}