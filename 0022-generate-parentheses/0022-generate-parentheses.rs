impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut ans = Vec::new();

        fn dfs(lp: i32, rp: i32, level: i32, current: String, n: i32, ans: &mut Vec<String>) {
            if lp == n && rp == n && level == 0 {
                ans.push(current);
                return;
            }
            if lp < n {
                dfs(lp + 1, rp, level + 1, current.clone() + "(", n, ans);
            }
            if rp < n && level >= 1 {
                dfs(lp, rp + 1, level - 1, current + ")", n, ans);
            }
        }

        dfs(1, 0, 1, "(".to_string(), n, &mut ans);
        ans
    }
}