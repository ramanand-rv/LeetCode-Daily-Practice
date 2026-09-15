impl Solution {
    pub fn max_palindromes(s: String, k: i32) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let mut ans = 0;
        let mut end: i32 = -1;
        for i in 0..n {
            for &start in &[i as i32 - 1, i as i32] {
                let mut l = start;
                let mut r = i as i32;
                while l >= 0 && r < n as i32 && s[l as usize] == s[r as usize] {
                    if r - l + 1 >= k && l > end {
                        ans += 1;
                        end = r;
                        break;
                    }
                    l -= 1;
                    r += 1;
                }
            }
        }
        ans
    }
}