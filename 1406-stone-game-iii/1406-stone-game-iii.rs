impl Solution {
    pub fn stone_game_iii(stone_value: Vec<i32>) -> String {
        let n = stone_value.len();
        let mut dp = [0, 0, 0, 0];

        for i in (0..n).rev() {
            let idx = i & 3; // equivalent to i % 4

            // take 1
            let mut best = stone_value[i] - dp[(i + 1) & 3];

            // take 2
            if i + 1 < n {
                best = best.max(stone_value[i] + stone_value[i + 1] - dp[(i + 2) & 3]);
            }

            // take 3
            if i + 2 < n {
                best = best.max(
                    stone_value[i] + stone_value[i + 1] + stone_value[i + 2] - dp[(i + 3) & 3]
                );
            }

            dp[idx] = best;
        }

        match dp[0] {
            d if d > 0 => "Alice".to_string(),
            d if d < 0 => "Bob".to_string(),
            _ => "Tie".to_string(),
        }
    }
}