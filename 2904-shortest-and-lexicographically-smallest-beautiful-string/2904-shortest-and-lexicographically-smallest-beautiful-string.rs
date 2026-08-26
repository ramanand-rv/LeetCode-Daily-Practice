impl Solution {
    pub fn shortest_beautiful_substring(s: String, k: i32) -> String {
        let s = s.as_bytes();
        let k = k as usize;
        let mut pos = Vec::new();

        // Store positions of all 1s
        for (i, &ch) in s.iter().enumerate() {
            if ch == b'1' {
                pos.push(i);
            }
        }

        // Not enough 1s
        if pos.len() < k {
            return String::new();
        }

        let mut ans = String::new();

        // Check every consecutive group of k ones
        for i in 0..=pos.len() - k {
            let start = pos[i];
            let end = pos[i + k - 1];
            let cur = String::from_utf8(s[start..=end].to_vec()).unwrap();

            if ans.is_empty()
                || cur.len() < ans.len()
                || (cur.len() == ans.len() && cur < ans)
            {
                ans = cur;
            }
        }

        ans
    }
}