impl Solution {
    pub fn minimum_cost(cost1: i32, cost2: i32, cost_both: i32, need1: i32, need2: i32) -> i64 {
        // Use i64 to prevent overflow during multiplication
        let c1 = cost1 as i64;
        let c2 = cost2 as i64;
        let cb = cost_both as i64;
        let n1 = need1 as i64;
        let n2 = need2 as i64;
        
        // We can cover min(need1, need2) units with a type-3 item
        let pairs = n1.min(n2);
        
        // For each pair, choose the cheaper option: type-3 OR type-1 + type-2
        let cost_pairs = pairs * cb.min(c1 + c2);
        
        // Remaining units of each type after covering the pairs
        let rem1 = n1 - pairs;
        let rem2 = n2 - pairs;
        
        // Cover remaining units with either their specific type OR a type-3 item
        let cost_rem = rem1 * c1.min(cb) + rem2 * c2.min(cb);
        
        cost_pairs + cost_rem
    }
}