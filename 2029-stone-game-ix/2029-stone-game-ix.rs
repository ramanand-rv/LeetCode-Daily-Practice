impl Solution {
    pub fn stone_game_ix(stones: Vec<i32>) -> bool {
        let mut cnt0: i32 = 0;
        let mut cnt1: i32 = 0;
        let mut cnt2: i32 = 0;

        for &x in &stones {
            match x % 3 {
                0 => cnt0 += 1,
                1 => cnt1 += 1,
                2 => cnt2 += 1,
                _ => unreachable!(),
            }
        }

        if cnt0 % 2 == 0 {
            return cnt1 > 0 && cnt2 > 0;
        }

        (cnt1 - cnt2).abs() > 2
    }
}