function pathExistenceQueries(n: number, nums: number[], maxDiff: number, queries: number[][]): boolean[] {
    const cmp: number[] = new Array(n).fill(0);

    for (let i = 1; i < n; i++) {
        const diff: number = Math.abs(nums[i] - nums[i - 1]);
        cmp[i] = cmp[i - 1] + (diff > maxDiff ? 1 : 0);
    }

    const results: boolean[] = new Array(queries.length);
    for (let i = 0; i < queries.length; i++) {
        const [l, r] = queries[i];
        results[i] = cmp[l] === cmp[r];
    }

    return results;
};