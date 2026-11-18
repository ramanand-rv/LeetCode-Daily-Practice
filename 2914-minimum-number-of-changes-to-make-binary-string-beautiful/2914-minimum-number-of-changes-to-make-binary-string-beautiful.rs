impl Solution {
    pub fn min_changes(s: String) -> i32 {
        let mut changes = 0;
        let bytes = s.as_bytes();
        // Loop through the string in steps of 2
        let mut i = 0;
        while i < bytes.len() {
            // If the two characters in the pair are different, one change is needed
            if bytes[i] != bytes[i + 1] {
                changes += 1;
            }
            i += 2;
        }
        changes
    }
}