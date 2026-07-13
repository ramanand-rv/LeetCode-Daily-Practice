impl Solution {
    pub fn sequential_digits(low: i32, high: i32) -> Vec<i32> {
        let mut result = Vec::new();

        for start in 1..=9 {
            let mut num = start;

            for next in (start + 1)..=9 {
                num = num * 10 + next;
                
                if num >= low && num <= high {
                    result.push(num);
                }
            }
        }

        result.sort();
        result
    }
}