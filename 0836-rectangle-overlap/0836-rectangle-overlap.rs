impl Solution {
    pub fn is_rectangle_overlap(rec1: Vec<i32>, rec2: Vec<i32>) -> bool {
        let left   = rec1[0].max(rec2[0]);
        let right  = rec1[2].min(rec2[2]);
        let bottom = rec1[1].max(rec2[1]);
        let top    = rec1[3].min(rec2[3]);
        left < right && bottom < top
    }
}