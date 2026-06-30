impl Solution {
    pub fn number_of_substrings(s: String) -> i32 {
        let n = s.len();
        let mut left = 0;
        let mut cnt = 0;
        let mut a = 0;
        let mut b = 0;
        let mut c = 0;

        let s = s.as_bytes();

        for right in 0..n {
            match s[right] {
                b'a' => a += 1,
                b'b' => b += 1,
                _ => c += 1,
            }

            while a > 0 && b > 0 && c > 0 {
                cnt += (n - right) as i32;

                match s[left] {
                    b'a' => a -= 1,
                    b'b' => b -= 1,
                    _ => c -= 1,
                }
                left += 1;
            }
        }

        cnt
    }
}