impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let mut tails = Vec::new();
        
        for &x in &nums {
            let mut low = 0;
            let mut high = tails.len();

            while low < high {
                let mut mid = low + ((high - low)/2);

                if(tails[mid] < x){
                    low = mid +1;
                }
                else{
                    high = mid;
                }
            }

            if(low == tails.len()){
                tails.push(x);
            }
            tails[low] = x;
        }
        return tails.len() as i32;
    }
}