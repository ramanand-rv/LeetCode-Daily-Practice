impl Solution {
    pub fn sum_and_multiply(n: i32) -> i64 {
        let mut n = n;
        let mut x: i64 = 0;
        let mut sum: i64 = 0;
        let mut len: i64 = 1;

        while n != 0 {
            let digit = (n % 10) as i64;
            x = digit * len + x;

            if digit != 0 {
                len *= 10;
            }

            sum += digit;
            n /= 10;
        }

        sum * x
    }
}