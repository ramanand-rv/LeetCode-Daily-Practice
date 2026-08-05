use std::collections::VecDeque;

impl Solution {
    pub fn remaining_methods(n: i32, k: i32, invocations: Vec<Vec<i32>>) -> Vec<i32> {
        let n = n as usize;
        let k = k as usize;
        let mut g = vec![vec![]; n];
        for e in &invocations {
            let u = e[0] as usize;
            let v = e[1] as usize;
            g[u].push(v);
        }

        let mut vis = vec![false; n];
        let mut q = VecDeque::new();
        q.push_back(k);
        vis[k] = true;
        while let Some(u) = q.pop_front() {
            for &v in &g[u] {
                if !vis[v] {
                    vis[v] = true;
                    q.push_back(v);
                }
            }
        }

        for e in &invocations {
            let u = e[0] as usize;
            let v = e[1] as usize;
            if !vis[u] && vis[v] {
                return (0..n as i32).collect();
            }
        }

        (0..n as i32)
            .filter(|&i| !vis[i as usize])
            .collect()
    }
}