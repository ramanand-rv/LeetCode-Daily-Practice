function removeCoveredIntervals(intervals: number[][]): number {
    intervals.sort(([u, v], [x, y]) => (u - x) || (y - v));
    let res = 0, lo = 0;

    for (const [_, b] of intervals) {
        if (b > lo) res += 1;
        lo = Math.max(lo, b);
    }

    return res;
};