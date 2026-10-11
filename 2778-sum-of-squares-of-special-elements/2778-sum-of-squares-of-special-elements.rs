impl Solution {
    pub fn sum_of_squares(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut sum = 0;

        for i in 1..n+1 {
            if (n % i == 0){
                sum = sum + nums[i-1] * nums[i-1];
            }
        }
        return sum as i32;
    }
}