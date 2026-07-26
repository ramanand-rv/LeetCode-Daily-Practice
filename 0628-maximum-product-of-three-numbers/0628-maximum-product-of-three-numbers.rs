impl Solution {
    pub fn maximum_product(nums: Vec<i32>) -> i32 {
        let mut max1 = -1000;
        let mut max2 = -1000;
        let mut max3 = -1000;
        let mut min1 = 0;
        let mut min2 = 0;

        for &ele in &nums {
            if ele >= max1 {
                max3 = max2;
                max2 = max1;
                max1 = ele;
            } else if ele >= max2 {
                max3 = max2;
                max2 = ele;
            } else if ele >= max3 {
                max3 = ele;
            }

            if ele <= min1 {
                min2 = min1;
                min1 = ele;
            } else if ele <= min2 {
                min2 = ele;
            }
        }

        (max1 * max2 * max3).max(min1 * min2 * max1)
    }
}