impl Solution {
    pub fn maximum_element_after_decrementing_and_rearranging(arr: Vec<i32>) -> i32 {
        let mut sorted = arr.clone();

        sorted.sort();

        sorted[0] = 1;

        for i in 1..sorted.len() {
            if(sorted[i] > sorted[i-1] +1){
                sorted[i] = sorted[i-1] +1;
            }
        }

        return sorted[sorted.len() -1];
    }
}