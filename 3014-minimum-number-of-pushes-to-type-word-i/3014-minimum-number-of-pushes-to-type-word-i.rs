impl Solution {
    pub fn minimum_pushes(word: String) -> i32 {
        let mut freq = [0; 26];
        for b in word.bytes() {
            freq[(b - b'a') as usize] += 1;
        }
        freq.sort_unstable_by(|a, b| b.cmp(a)); // descending

        let mut res = 0;
        for (i, &cnt) in freq.iter().enumerate() {
            if cnt == 0 { break; }
            res += if i < 8 {
                cnt
            } else if i < 16 {
                cnt * 2
            } else if i < 24 {
                cnt * 3
            } else {
                cnt * 4
            };
        }
        res
    }
}