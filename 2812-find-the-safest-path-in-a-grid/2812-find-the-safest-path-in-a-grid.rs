use std::collections::VecDeque;

impl Solution {
    pub fn maximum_safeness_factor(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let dirs = vec![(-1, 0), (1, 0), (0, -1), (0, 1)];
        
        // Step 1: Multi-Source BFS
        let mut dist = vec![vec![i32::MAX; n]; n];
        let mut q = VecDeque::new();
        
        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 1 {
                    dist[i][j] = 0;
                    q.push_back((i, j));
                }
            }
        }
        
        while let Some((r, c)) = q.pop_front() {
            for &(dr, dc) in &dirs {
                let nr = r as isize + dr;
                let nc = c as isize + dc;
                if nr >= 0 && nr < n as isize && nc >= 0 && nc < n as isize {
                    let nr = nr as usize;
                    let nc = nc as usize;
                    if dist[nr][nc] == i32::MAX {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push_back((nr, nc));
                    }
                }
            }
        }
        
        // Step 2: Binary Search
        let can_reach = |limit: i32| -> bool {
            if dist[0][0] < limit {
                return false;
            }
            
            let mut vis = vec![vec![false; n]; n];
            let mut q = VecDeque::new();
            q.push_back((0, 0));
            vis[0][0] = true;
            
            while let Some((r, c)) = q.pop_front() {
                if r == n - 1 && c == n - 1 {
                    return true;
                }
                
                for &(dr, dc) in &dirs {
                    let nr = r as isize + dr;
                    let nc = c as isize + dc;
                    if nr >= 0 && nr < n as isize && nc >= 0 && nc < n as isize {
                        let nr = nr as usize;
                        let nc = nc as usize;
                        if !vis[nr][nc] && dist[nr][nc] >= limit {
                            vis[nr][nc] = true;
                            q.push_back((nr, nc));
                        }
                    }
                }
            }
            
            false
        };
        
        let mut low = 0;
        let mut high = (2 * n) as i32;
        let mut ans = 0;
        
        while low <= high {
            let mid = low + (high - low) / 2;
            if can_reach(mid) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        ans
    }
}