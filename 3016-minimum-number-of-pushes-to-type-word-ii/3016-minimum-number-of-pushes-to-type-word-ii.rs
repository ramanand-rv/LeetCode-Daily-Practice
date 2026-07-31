impl Solution {
    pub fn minimum_pushes(word: String) -> i32 {
        let mut freq = [0; 26];
        for b in word.bytes() {
            freq[(b - b'a') as usize] += 1;
        }
        freq.sort_unstable(); // ascending

        let mut min_pushes = 0;
        let mut push_cnt = 0;
        for i in (0..26).rev() {
            let curr_idx = 25 - i;
            if curr_idx % 8 == 0 {
                push_cnt += 1;
            }
            min_pushes += freq[i] * push_cnt;
        }
        min_pushes
    }
}