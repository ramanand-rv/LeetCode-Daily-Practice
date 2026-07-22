class SparseTable {
    private st: number[][];

    constructor(data: number[]) {
        this.st = [data];
        let i = 1;
        const N = data.length;
        while (2 * i <= N + 1) {
            const pre = this.st[this.st.length - 1];
            const cur: number[] = [];
            for (let j = 0; j < N - 2 * i + 1; j++) {
                cur.push(Math.max(pre[j], pre[j + i]));
            }
            this.st.push(cur);
            i <<= 1;
        }
    }

    query(begin: number, end: number): number {
        if (begin > end) return 0;
        const len = end - begin + 1;
        let lg = 0;
        while ((1 << (lg + 1)) <= len) lg++;
        return Math.max(
            this.st[lg][begin],
            this.st[lg][end - (1 << lg) + 1]
        );
    }
}

function maxActiveSectionsAfterTrade(s: string, queries: number[][]): number[] {
    const n = s.length;
    const cnt1 = s.split('').filter(ch => ch === '1').length;

    const zeroBlocks: number[] = [];
    const blockLeft: number[] = [];
    const blockRight: number[] = [];

    let i = 0;
    while (i < n) {
        const start = i;
        while (i < n && s[i] === s[start]) i++;
        if (s[start] === '0') {
            zeroBlocks.push(i - start);
            blockLeft.push(start);
            blockRight.push(i - 1);
        }
    }

    const m = zeroBlocks.length;
    if (m < 2) {
        return queries.map(() => cnt1);
    }

    const tmpSum: number[] = [];
    for (let i = 0; i < m - 1; i++) {
        tmpSum.push(zeroBlocks[i] + zeroBlocks[i + 1]);
    }
    const st = new SparseTable(tmpSum);

    const ans: number[] = [];
    for (const [l, r] of queries) {
        // first zero block intersecting [l, r]
        let i = lowerBound(blockRight, l);
        // last zero block intersecting [l, r]
        let j = upperBound(blockLeft, r) - 1;

        if (i > j || i === j) {
            ans.push(cnt1);
            continue;
        }

        const firstLen = blockRight[i] - Math.max(blockLeft[i], l) + 1;
        const lastLen = Math.min(blockRight[j], r) - blockLeft[j] + 1;

        let bestGain: number;
        if (i + 1 === j) {
            bestGain = firstLen + lastLen;
        } else {
            const gain1 = firstLen + zeroBlocks[i + 1];
            const gain2 = zeroBlocks[j - 1] + lastLen;
            const gain3 = st.query(i + 1, j - 2);
            bestGain = Math.max(gain1, gain2, gain3);
        }
        ans.push(cnt1 + bestGain);
    }
    return ans;
}

// Binary search helpers
function lowerBound(arr: number[], target: number): number {
    let lo = 0, hi = arr.length;
    while (lo < hi) {
        const mid = (lo + hi) >> 1;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

function upperBound(arr: number[], target: number): number {
    let lo = 0, hi = arr.length;
    while (lo < hi) {
        const mid = (lo + hi) >> 1;
        if (arr[mid] <= target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}