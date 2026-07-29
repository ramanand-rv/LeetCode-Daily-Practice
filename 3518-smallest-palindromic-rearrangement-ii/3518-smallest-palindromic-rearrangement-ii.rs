impl Solution {
    pub fn smallest_palindrome(s: String, mut k: i32) -> String {
        let n = s.len();
        let half = n / 2;
        let mut freq = [0; 26];
        for b in s.bytes() {
            freq[(b - b'a') as usize] += 1;
        }

        let mut res = vec![' '; n];
        // middle character
        for i in 0..26 {
            if (freq[i] & 1) == 1 {
                res[n / 2] = (b'a' + i as u8) as char;
            }
            freq[i] /= 2;
        }

        let ncr = |n: i32, mut r: i32, limit: i32| -> i32 {
            r = r.min(n - r);
            let mut ans = 1i64;
            for i in 1..=r {
                ans = ans * (n - i + 1) as i64 / i as i64;
                if ans > limit as i64 { return limit + 1; }
            }
            ans as i32
        };

        let ways = |rem: i32, f: &[i32], limit: i32| -> i32 {
            let mut total = 1i64;
            let mut rem = rem;
            for i in 0..26 {
                total *= ncr(rem, f[i], limit) as i64;
                if total > limit as i64 { return limit + 1; }
                rem -= f[i];
            }
            total as i32
        };

        let total = ways(half as i32, &freq, k);
        if total < k { return String::new(); }

        for idx in 0..half {
            for i in 0..26 {
                if freq[i] == 0 { continue; }
                freq[i] -= 1;
                let possible = ways((half - idx - 1) as i32, &freq, k);
                if possible >= k {
                    res[idx] = (b'a' + i as u8) as char;
                    break;
                } else {
                    k -= possible;
                    freq[i] += 1;
                }
            }
        }

        for i in 0..half {
            res[n - 1 - i] = res[i];
        }
        res.iter().collect()
    }
}