impl Solution {
    pub fn missing_integer(nums: Vec<i32>) -> i32 {
        let mut seqSum:i32 = nums[0];

        for i in 1..nums.len() {
            if nums[i] == nums[i -1] +1 {
                seqSum += nums[i];
            }
            else {
                break;
            }
        }

        let mut present = vec![false; 1276];

        for &num in &nums {
            present[num as usize] = true;
        }

        while present[seqSum as usize] {
            seqSum += 1;
        }

        seqSum
    }
}