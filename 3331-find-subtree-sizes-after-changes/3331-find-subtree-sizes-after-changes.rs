impl Solution {
    pub fn find_subtree_sizes(mut p: Vec<i32>, s: String) -> Vec<i32> {
        let n = p.len();
        let mut adj = vec![vec![]; n];
        for i in 1..n {
            adj[p[i] as usize].push(i as i32);
        }
        
        let mut last = vec![-1i32; 26];
        let s_bytes = s.as_bytes();
        
        // DFS to update parents
        fn dfs(u: usize, adj: &Vec<Vec<i32>>, s_bytes: &[u8], p: &mut Vec<i32>, last: &mut Vec<i32>) {
            let c = (s_bytes[u] - b'a') as usize;
            let old = last[c];
            if u != 0 && old != -1 {
                p[u] = old;
            }
            last[c] = u as i32;
            for &v in &adj[u] {
                dfs(v as usize, adj, s_bytes, p, last);
            }
            last[c] = old;
        }
        
        dfs(0, &adj, s_bytes, &mut p, &mut last);
        
        // Build new tree
        let mut tree = vec![vec![]; n];
        for i in 1..n {
            tree[p[i] as usize].push(i as i32);
        }
        
        // Calculate subtree sizes
        let mut ans = vec![0i32; n];
        fn calc(u: usize, tree: &Vec<Vec<i32>>, ans: &mut Vec<i32>) -> i32 {
            ans[u] = 1;
            for &v in &tree[u] {
                ans[u] += calc(v as usize, tree, ans);
            }
            ans[u]
        }
        calc(0, &tree, &mut ans);
        
        ans
    }
}