use std::collections::HashMap;

impl Solution {
    pub fn array_rank_transform(arr: Vec<i32>) -> Vec<i32> {
        // Sort unique values
        let mut sorted = arr.clone();
        sorted.sort();
        sorted.dedup(); // remove duplicates
        
        // Build mapping value -> rank (1-based)
        let mut rank_map = HashMap::new();
        for (i, &val) in sorted.iter().enumerate() {
            rank_map.insert(val, (i + 1) as i32);
        }
        
        // Replace each element
        arr.iter().map(|x| *rank_map.get(x).unwrap()).collect()
    }
}
