use std::collections::BTreeMap;

impl Solution {
    pub fn maximum_weight(intervals: Vec<Vec<i32>>) -> Vec<i32> {
        // Deduplicate: BTreeMap keeps sorted order, stores smallest index
        let mut map: BTreeMap<(i32, i32, i32), usize> = BTreeMap::new();
        for (i, v) in intervals.iter().enumerate() {
            let key = (v[0], v[1], v[2]);
            map.entry(key).or_insert(i);
        }
        let arr: Vec<(i32, i32, i32, usize)> = map
            .into_iter()
            .map(|((l, r, w), idx)| (l, r, w, idx))
            .collect();
        let n = arr.len();

        // nextIndex[i] = first interval j > i with left > right_i
        let mut next_index = vec![n; n];
        for i in 0..n {
            let r = arr[i].1;
            let mut lo = i + 1;
            let mut hi = n;
            while lo < hi {
                let mid = (lo + hi) / 2;
                if arr[mid].0 > r {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            next_index[i] = lo;
        }

        // dp[i][k] = (neg_weight, indices)
        let mut dp = vec![vec![(0i64, Vec::<usize>::new()); 5]; n + 1];
        for i in (0..n).rev() {
            let (_, _, w, idx) = arr[i];
            for k in 1..=4 {
                let skip = &dp[i + 1][k];
                let take_base = &dp[next_index[i]][k - 1];
                let mut new_indices = take_base.1.clone();
                new_indices.push(idx);
                new_indices.sort();
                let take = (take_base.0 - w as i64, new_indices);
                // Tuple ordering: first neg_weight (smaller = better), then indices lexicographically
                dp[i][k] = if skip < &take { skip.clone() } else { take };
            }
        }
        dp[0][4].1.iter().map(|&x| x as i32).collect()
    }
}