impl Solution {
    pub fn find_the_distance_value(mut arr1: Vec<i32>, mut arr2: Vec<i32>, d: i32) -> i32 {
        arr1.sort_unstable();
        arr2.sort_unstable();
        
        let mut ans = 0;
        let mut j = 0;
        
        for &x in &arr1 {
            // Advance j to the first element in arr2 that is >= x - d
            while j < arr2.len() && arr2[j] < x - d {
                j += 1;
            }
            
            // If no such element exists, or it's strictly greater than x + d, x is valid
            if j == arr2.len() || arr2[j] > x + d {
                ans += 1;
            }
        }
        
        ans
    }
}