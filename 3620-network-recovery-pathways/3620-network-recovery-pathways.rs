use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn find_max_path_score(edges: Vec<Vec<i32>>, online: Vec<bool>, k: i64) -> i32 {
        let n = online.len();

        let mut adj = vec![vec![]; n];
        let mut low = i32::MAX;
        let mut high = i32::MIN;

        for e in &edges {

            let u = e[0] as usize;
            let v = e[1] as usize;
            let cst = e[2];

            adj[u].push((v, cst));

            low = low.min(cst);
            high = high.max(cst);
        }

        if edges.is_empty() {
            return if n == 1 { 0 } else { -1 };
        }

        let can_reach = |limit: i32| -> bool {

            const INF: i64 = i64::MAX / 2;
            let mut dist = vec![INF; n];
            dist[0] = 0;
            let mut pq = BinaryHeap::new();
            pq.push(Reverse((0, 0)));

            while let Some(Reverse((cur_cost, node))) = pq.pop() {

                if cur_cost > dist[node] { continue; }
                if node == n - 1 { break; }

                for &(nxt_node, weight) in &adj[node] {

                    if weight < limit { continue; }
                    if nxt_node != n - 1 && !online[nxt_node] { continue; }

                    let new_cost = cur_cost + weight as i64;
                    
                    if new_cost < dist[nxt_node] {
                        dist[nxt_node] = new_cost;
                        pq.push(Reverse((new_cost, nxt_node)));
                    }
                }
            }

            dist[n - 1] <= k
        };

        let mut res = -1;
        let (mut lo, mut hi) = (low, high);
        while lo <= hi {
            let mid = lo + (hi - lo) / 2;
            if can_reach(mid) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        res
    }
}