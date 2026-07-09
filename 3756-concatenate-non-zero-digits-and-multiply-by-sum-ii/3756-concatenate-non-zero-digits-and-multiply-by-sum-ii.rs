impl Solution {
    const MOD: i64 = 1_000_000_007;
    const MAX: usize = 100_001;
    
    pub fn sum_and_multiply(s: String, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let s = s.as_bytes();
        let n = s.len();
        
        let mut pow10 = vec![0i64; Self::MAX];
        pow10[0] = 1;
        for i in 1..Self::MAX {
            pow10[i] = (pow10[i - 1] * 10) % Self::MOD;
        }
        
        let mut A = vec![0i64; n + 1];
        let mut B = vec![0i64; n + 1];
        let mut len = vec![0i64; n + 1];
        
        for i in 0..n {
            let d = (s[i] - b'0') as i64;
            
            A[i + 1] = A[i] + d;
            
            if d != 0 {
                B[i + 1] = (B[i] * 10 + d) % Self::MOD;
                len[i + 1] = len[i] + 1;
            } else {
                B[i + 1] = B[i];
                len[i + 1] = len[i];
            }
        }
        
        let mut results = Vec::with_capacity(queries.len());
        
        for query in &queries {
            let l = query[0] as usize;
            let r = query[1] as usize + 1;
            
            let ln = (len[r] - len[l]) as usize;
            let sub = (B[l] * pow10[ln]) % Self::MOD;
            let mut x = (B[r] - sub) % Self::MOD;
            if x < 0 { x += Self::MOD; }
            
            results.push(((x * (A[r] - A[l])) % Self::MOD) as i32);
        }
        
        results
    }
}