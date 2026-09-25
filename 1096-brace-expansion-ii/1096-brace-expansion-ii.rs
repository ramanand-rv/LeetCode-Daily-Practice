use std::collections::HashSet;

impl Solution {
    pub fn brace_expansion_ii(expression: String) -> Vec<String> {
        let mut ans = HashSet::new();

        fn dfs(s: String, ans: &mut HashSet<String>) {
            if let Some(r) = s.find('}') {
                let l = s[..r].rfind('{').unwrap();
                let left = &s[..l];
                let right = &s[r + 1..];
                let inside = &s[l + 1..r];
                for part in inside.split(',') {
                    let new_s = format!("{}{}{}", left, part, right);
                    dfs(new_s, ans);
                }
            } else {
                ans.insert(s);
            }
        }

        dfs(expression, &mut ans);
        let mut result: Vec<String> = ans.into_iter().collect();
        result.sort();
        result
    }
}