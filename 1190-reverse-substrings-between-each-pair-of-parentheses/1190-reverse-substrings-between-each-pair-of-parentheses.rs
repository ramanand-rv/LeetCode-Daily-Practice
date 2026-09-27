impl Solution {
    pub fn reverse_parentheses(s: String) -> String {
        let n = s.len();
        let bytes = s.as_bytes();
        let mut match_idx = vec![0; n];
        let mut stack = Vec::new();

        for i in 0..n {
            if bytes[i] == b'(' {
                stack.push(i);
            } else if bytes[i] == b')' {
                let j = stack.pop().unwrap();
                match_idx[i] = j;
                match_idx[j] = i;
            }
        }

        let mut ans = String::new();
        let mut i: i32 = 0;
        let mut dir: i32 = 1;
        while i >= 0 && (i as usize) < n {
            let idx = i as usize;
            if bytes[idx] == b'(' || bytes[idx] == b')' {
                i = match_idx[idx] as i32;
                dir = -dir;
            } else {
                ans.push(bytes[idx] as char);
            }
            i += dir;
        }
        ans
    }
}