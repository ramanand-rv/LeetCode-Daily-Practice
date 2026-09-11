impl Solution {
    pub fn total_numbers(digits: Vec<i32>) -> i32 {
        let mut freq = [0; 10];
        for d in digits {
            freq[d as usize] += 1;
        }
        let mut count = 0;

        for h in 1..=9 {
            if freq[h] == 0 { continue; }
            freq[h] -= 1;

            for t in 0..=9 {
                if freq[t] == 0 { continue; }
                freq[t] -= 1;
                
                for u in (0..=8).step_by(2) {
                    if freq[u] > 0 { count += 1; }
                }
                freq[t] += 1;
            }
            freq[h] += 1;
        }
        count
    }
}