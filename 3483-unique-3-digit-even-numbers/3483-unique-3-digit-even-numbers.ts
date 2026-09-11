function totalNumbers(digits: number[]): number {
    const freq = new Array(10).fill(0);
    for (const d of digits) freq[d]++;
    let count = 0;

    for (let h = 1; h <= 9; h++) {
        if (freq[h] === 0) continue;
        freq[h]--;
        for (let t = 0; t <= 9; t++) {
            if (freq[t] === 0) continue;
            freq[t]--;
            for (let u = 0; u <= 8; u += 2) {
                if (freq[u] > 0) count++;
            }
            freq[t]++;
        }
        freq[h]++;
    }
    return count;
}