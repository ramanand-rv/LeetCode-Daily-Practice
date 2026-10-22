impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let shift = nums.iter().position(|&x| x == 0).unwrap();

        let ring = |k: usize| -> i32 {
            nums[(shift + k) % n]
        };

        let mut ok = true;
        for k in 0..n {
            if ring(k) != k as i32 {
                ok = false;
                break;
            }
        }
        if ok {
            return shift.min(n - shift + 2) as i32;
        }

        ok = true;
        for k in 0..n {
            if ring(k) != ((n - k) % n) as i32 {
                ok = false;
                break;
            }
        }
        if ok {
            return (shift + 2).min(n - shift) as i32;
        }

        -1
    }
}