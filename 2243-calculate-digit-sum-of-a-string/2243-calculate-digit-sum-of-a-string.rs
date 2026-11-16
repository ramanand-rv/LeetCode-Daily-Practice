impl Solution {
    pub fn digit_sum(s: String, k: i32) -> String {
        let mut s = s;
        let k = k as usize;
        
        // Keep shrinking the string until its length is at most k
        while s.len() > k {
            let mut next = String::new();
            let bytes = s.as_bytes();
            
            // Process the string in chunks of size k
            for i in (0..s.len()).step_by(k) {
                let mut sum = 0;
                let end = (i + k).min(s.len());
                
                // Sum the digits in the current chunk
                for j in i..end {
                    sum += (bytes[j] - b'0') as i32;
                }
                
                // Append the sum to the next string
                next.push_str(&sum.to_string());
            }
            
            // Update s for the next round
            s = next;
        }
        
        s
    }
}