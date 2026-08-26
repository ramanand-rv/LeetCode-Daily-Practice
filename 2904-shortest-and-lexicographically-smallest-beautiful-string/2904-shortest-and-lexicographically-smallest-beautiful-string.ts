function shortestBeautifulSubstring(s: string, k: number): string {
    const n = s.length;
    let left = 0;
    let ones = 0;
    let ans = "";

    for (let right = 0; right < n; right++) {
        if (s[right] === '1') ones++;

        // Too many ones → shrink from left
        while (ones > k) {
            if (s[left] === '1') ones--;
            left++;
        }

        // We have exactly k ones
        if (ones === k) {
            // Remove unnecessary leading zeros
            while (left < right && s[left] === '0') {
                left++;
            }

            const cur = s.substring(left, right + 1);

            if (ans === "" ||
                cur.length < ans.length ||
                (cur.length === ans.length && cur < ans)) {
                ans = cur;
            }
        }
    }

    return ans;
}