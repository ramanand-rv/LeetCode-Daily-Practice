impl Solution {
    pub fn smallest_subsequence(s: String) -> String {
        let s = s.as_bytes();
        let mut last = [-1; 26];
        for (i, &ch) in s.iter().enumerate() {
            last[(ch - b'a') as usize] = i as i32;
        }

        let mut in_stack = [false; 26];
        let mut stack: Vec<u8> = Vec::new();

        for (i, &ch) in s.iter().enumerate() {
            let idx = (ch - b'a') as usize;

            if in_stack[idx] {
                continue;
            }

            while let Some(&top) = stack.last() {
                let top_idx = (top - b'a') as usize;
                if top > ch && last[top_idx] > i as i32 {
                    in_stack[top_idx] = false;
                    stack.pop();
                } else {
                    break;
                }
            }

            stack.push(ch);
            in_stack[idx] = true;
        }

        String::from_utf8(stack).unwrap()
    }
}