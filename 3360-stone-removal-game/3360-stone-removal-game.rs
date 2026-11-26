impl Solution {
    pub fn can_alice_win(n: i32) -> bool {
        // All 10 moves would require 55 stones (10+9+...+1)
        let missing = 55 - n;
        
        // Find the number of unplayed moves (the smallest j such that 1+2+...+j >= missing)
        // This simplifies to j = round(sqrt(2 * missing))
        let unplayed = (2.0 * missing as f64).sqrt().round() as i32;
        
        // If the number of unplayed moves is odd, the number of played moves is also odd (10 - odd = odd)
        // Odd number of moves means Alice made the last move and wins
        unplayed % 2 == 1
    }
}