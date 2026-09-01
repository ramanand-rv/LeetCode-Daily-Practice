use std::collections::VecDeque;

struct State {
    r: usize,
    c: usize,
    mask: usize,
    en: i32,
    dist: i32,
}

impl Solution {
    pub fn min_moves(classroom: Vec<String>, energy: i32) -> i32 {
        let m = classroom.len();
        let n = classroom[0].len();
        let classroom: Vec<Vec<char>> = classroom.iter().map(|s| s.chars().collect()).collect();

        let mut sr = 0;
        let mut sc = 0;
        let mut cnt = 0;
        let mut id = vec![vec![-1; n]; m];

        for i in 0..m {
            for j in 0..n {
                if classroom[i][j] == 'S' { sr = i; sc = j; }
                if classroom[i][j] == 'L' { id[i][j] = cnt; cnt += 1; }
            }
        }

        let masks = 1 << cnt;
        let full_mask = masks - 1;

        let mut best = vec![vec![vec![-1; masks]; n]; m];
        best[sr][sc][0] = energy;

        let mut queue = VecDeque::new();
        queue.push_back(State { r: sr, c: sc, mask: 0, en: energy, dist: 0 });

        let dr = [-1, 1, 0, 0];
        let dc = [0, 0, -1, 1];

        while let Some(State { r, c, mask, en, dist }) = queue.pop_front() {
            if mask == full_mask { return dist; }
            if en == 0 { continue; }

            for d in 0..4 {
                let nr = (r as isize + dr[d]) as usize;
                let nc = (c as isize + dc[d]) as usize;

                if nr >= m || nc >= n { continue; }
                if classroom[nr][nc] == 'X' { continue; }

                let mut new_en = en - 1;
                let mut new_mask = mask;

                if classroom[nr][nc] == 'L' {
                    new_mask |= 1 << id[nr][nc];
                }
                if classroom[nr][nc] == 'R' {
                    new_en = energy;
                }

                if best[nr][nc][new_mask] >= new_en { continue; }

                best[nr][nc][new_mask] = new_en;
                queue.push_back(State {
                    r: nr,
                    c: nc,
                    mask: new_mask,
                    en: new_en,
                    dist: dist + 1,
                });
            }
        }
        -1
    }
}