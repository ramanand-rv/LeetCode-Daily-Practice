impl Solution {
    pub fn count_servers(n: i32, mut logs: Vec<Vec<i32>>, x: i32, queries: Vec<i32>) -> Vec<i32> {
        // Sort logs by request time
        logs.sort_unstable_by_key(|log| log[1]);
        
        // Pair queries with original indices and sort by time
        let mut q: Vec<(i32, usize)> = queries.into_iter().enumerate().map(|(i, t)| (t, i)).collect();
        q.sort_unstable_by_key(|&(t, _)| t);
        
        let mut cnt = vec![0; (n + 1) as usize];
        let mut ans = vec![0; q.len()];
        let mut l = 0;
        let mut r = 0;
        let mut active = 0;
        
        for (t, idx) in q {
            // Add logs within time <= t
            while r < logs.len() && logs[r][1] <= t {
                let server_id = logs[r][0] as usize;
                cnt[server_id] += 1;
                // If this server becomes active, increment active count
                if cnt[server_id] == 1 {
                    active += 1;
                }
                r += 1;
            }
            
            // Remove logs strictly outside the window (time < t - x)
            while l < r && logs[l][1] < t - x {
                let server_id = logs[l][0] as usize;
                cnt[server_id] -= 1;
                // If this server becomes inactive, decrement active count
                if cnt[server_id] == 0 {
                    active -= 1;
                }
                l += 1;
            }
            
            // Inactive servers = total servers - active servers
            ans[idx] = n - active;
        }
        
        ans
    }
}