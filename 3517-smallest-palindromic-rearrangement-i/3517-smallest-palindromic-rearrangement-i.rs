impl Solution {
    pub fn smallest_palindrome(s: String) -> String {
        let n = s.len();
        let mut freq = [0; 26];
        let bytes = s.as_bytes();

        // Count first half
        for i in 0..n/2 {
            let idx = (bytes[i] & 31) as usize - 1;
            freq[idx] += 1;
        }

        let mut arr: Vec<u8> = bytes.to_vec();
        let mut j = 0;
        for i in 0..26 {
            while freq[i] > 0 {
                arr[j] = (b'a' + i as u8);
                arr[n - 1 - j] = (b'a' + i as u8);
                j += 1;
                freq[i] -= 1;
            }
        }

        String::from_utf8(arr).unwrap()
    }
}