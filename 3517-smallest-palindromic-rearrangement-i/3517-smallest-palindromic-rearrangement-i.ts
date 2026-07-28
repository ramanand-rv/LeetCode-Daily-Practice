function smallestPalindrome(s: string): string {
    const n = s.length;
    const freq = new Array(26).fill(0);
    const arr = s.split('');

    // Count first half
    for (let i = 0; i < n >> 1; i++) {
        const idx = (s.charCodeAt(i) & 31) - 1;
        freq[idx]++;
    }

    let j = 0;
    for (let i = 0; i < 26; i++) {
        while (freq[i] > 0) {
            arr[j] = String.fromCharCode(97 + i);
            arr[n - 1 - j] = String.fromCharCode(97 + i);
            j++;
            freq[i]--;
        }
    }

    return arr.join('');
}