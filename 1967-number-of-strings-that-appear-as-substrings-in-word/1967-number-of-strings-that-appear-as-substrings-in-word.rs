impl Solution {
    pub fn num_of_strings(patterns: Vec<String>, word: String) -> i32 {
        let mut substring:i32 = 0;
        
        for s in patterns {
            if(word.contains(&s)) {
                substring += 1;
            }
        }

        return substring;
    }
}