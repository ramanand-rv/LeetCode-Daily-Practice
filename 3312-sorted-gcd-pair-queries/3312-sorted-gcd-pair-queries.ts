function gcdValues(A: number[], queries: number[]): number[] {
    const maxVal = Math.max(...A);
    const freq = new Array(maxVal + 1).fill(0);
    for (const x of A) freq[x]++;

    const mFreq = new Array(maxVal + 1).fill(0);
    const pairs = new Array(maxVal + 1).fill(0);
    const gcdExact = new Array(maxVal + 1).fill(0);

    for (let g = maxVal; g >= 1; g--) {
        let total = 0;
        let overlap = 0;
        for (let mult = g; mult <= maxVal; mult += g) {
            total += freq[mult];
            overlap += gcdExact[mult];
        }
        mFreq[g] = total;
        pairs[g] = total * (total - 1) / 2;
        gcdExact[g] = pairs[g] - overlap;
    }

    // prefix sum
    for (let i = 1; i <= maxVal; i++) {
        gcdExact[i] += gcdExact[i - 1];
    }

    // binary search (upper_bound)
    const upperBound = (arr: number[], target: number): number => {
        let lo = 0, hi = arr.length;
        while (lo < hi) {
            const mid = (lo + hi) >> 1;
            if (arr[mid] <= target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    };

    const res: number[] = [];
    for (const q of queries) {
        res.push(upperBound(gcdExact, q));
    }
    return res;
}