impl Solution {
    pub fn find_gcd(nums: Vec<i32>) -> i32 {
        let mn = *nums.iter().min().unwrap();
        let mx = *nums.iter().max().unwrap();
        gcd(mn, mx)
    }
}


fn gcd(mut a: i32, mut b: i32) -> i32 {
    while b != 0 {
        let temp = b;
        b = a % b;
        a = temp;
    }
    a
}