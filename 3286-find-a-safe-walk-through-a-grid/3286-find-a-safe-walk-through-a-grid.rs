use std::collections::VecDeque;

impl Solution {
    pub fn find_safe_walk(grid: Vec<Vec<i32>>, health: i32) -> bool {
        let m = grid.len();
        let n = grid[0].len();

        let inf = i32::MAX;
        
        let mut dist = vec![vec![inf; n]; m];

        dist[0][0] = grid[0][0];
        
        let mut dq = VecDeque::new();

        dq.push_back((0, 0));
        
        let dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)];
        
        while let Some((x, y)) = dq.pop_front() {
            for &(dx, dy) in &dirs {
                let nx = x as isize + dx;
                let ny = y as isize + dy;
                
                if nx < 0 || ny < 0 || nx >= m as isize || ny >= n as isize {
                    continue;
                }
                
                let nx = nx as usize;
                let ny = ny as usize;
                let w = grid[nx][ny];
                
                if dist[x][y] + w < dist[nx][ny] {
                    dist[nx][ny] = dist[x][y] + w;
                    
                    if w == 0 {
                        dq.push_front((nx, ny));
                    } else {
                        dq.push_back((nx, ny));
                    }
                }
            }
        }
        
        dist[m - 1][n - 1] < health
    }
}