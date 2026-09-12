function maximumWeight(intervals: number[][]): number[] {
    // Deduplicate: keep smallest original index for identical (left,right,weight)
    const map = new Map<string, number>();
    for (let i = 0; i < intervals.length; i++) {
        const [l, r, w] = intervals[i];
        const key = `${l},${r},${w}`;
        if (!map.has(key)) map.set(key, i);
    }
    const arr: [number, number, number, number][] = [];
    for (const [key, idx] of map) {
        const [l, r, w] = key.split(',').map(Number);
        arr.push([l, r, w, idx]);
    }
    arr.sort((a, b) => a[0] - b[0] || a[1] - b[1] || a[2] - b[2]);
    const n = arr.length;

    // nextIndex[i] = first interval j > i with left > right_i
    const nextIndex = new Array(n).fill(n);
    for (let i = 0; i < n; i++) {
        const r = arr[i][1];
        let lo = i + 1, hi = n;
        while (lo < hi) {
            const mid = (lo + hi) >> 1;
            if (arr[mid][0] > r) hi = mid;
            else lo = mid + 1;
        }
        nextIndex[i] = lo;
    }

    type P = { weight: number; indices: number[] };
    const dp: P[][] = Array.from({ length: n + 1 }, () =>
        Array.from({ length: 5 }, () => ({ weight: 0, indices: [] }))
    );

    const compare = (a: P, b: P): number => {
        if (a.weight !== b.weight) return a.weight - b.weight; // negative weight -> more negative = better
        for (let i = 0; i < Math.min(a.indices.length, b.indices.length); i++) {
            if (a.indices[i] !== b.indices[i]) return a.indices[i] - b.indices[i];
        }
        return a.indices.length - b.indices.length;
    };

    for (let i = n - 1; i >= 0; i--) {
        const [_, __, w, idx] = arr[i];
        for (let k = 1; k <= 4; k++) {
            const skip = dp[i + 1][k];
            const takeBase = dp[nextIndex[i]][k - 1];
            const newIndices = [...takeBase.indices, idx].sort((a, b) => a - b);
            const take: P = { weight: takeBase.weight - w, indices: newIndices };
            dp[i][k] = compare(skip, take) <= 0 ? skip : take;
        }
    }
    return dp[0][4].indices;
}