impl Solution {
    pub fn maximum_sale_items(items: Vec<Vec<i32>>, budget: i32) -> i32 {
        let n = items.len();
        let mut factors = vec![0; n];
        let mut prices = vec![0; n];
        for i in 0..n {
            factors[i] = items[i][0];
            prices[i] = items[i][1];
        }

        // Find the cheapest item to fill leftover budget
        let cheapest = *prices.iter().min().unwrap();

        // best[m] stores max copies for 'm' budget
        let mut best = vec![0; (budget + 1) as usize];
        for m in 0..=budget as usize {
            best[m] = (m as i32 / cheapest) as i32; // Baseline
        }

        for i in 0..n {
            let factor = factors[i];
            let price = prices[i];
            
            // Calculate the gain (number of multiples)
            let mut gain = 0;
            for &other in &factors {
                if other % factor == 0 {
                    gain += 1;
                }
            }

            // Only process if gain is better than spending money on the cheapest item
            if gain > price / cheapest {
                // 0/1 Knapsack: iterate backwards to avoid reusing the same first copy
                for m in (price..=budget).rev() {
                    let candidate = best[(m - price) as usize] + gain;
                    if candidate > best[m as usize] {
                        best[m as usize] = candidate;
                    }
                }
            }
        }

        best[budget as usize]
    }
}