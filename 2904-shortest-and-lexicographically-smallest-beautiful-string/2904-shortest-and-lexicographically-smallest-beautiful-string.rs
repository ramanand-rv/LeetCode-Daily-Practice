impl Solution {
    pub fn shortest_beautiful_substring(s: String, k: i32) -> String {
        let s = s.as_bytes();
        let n = s.len();
        let k = k as usize;
        let mut left = 0;
        let mut ones = 0;
        let mut ans = String::new();

        for right in 0..n {
            if s[right] == b'1' {
                ones += 1;
            }

            // Too many ones → shrink from left
            while ones > k {
                if s[left] == b'1' {
                    ones -= 1;
                }
                left += 1;
            }

            // We have exactly k ones
            if ones == k {
                // Remove unnecessary leading zeros
                while left < right && s[left] == b'0' {
                    left += 1;
                }

                let cur = String::from_utf8(s[left..=right].to_vec()).unwrap();

                if ans.is_empty()
                    || cur.len() < ans.len()
                    || (cur.len() == ans.len() && cur < ans)
                {
                    ans = cur;
                }
            }
        }

        ans
    }
}