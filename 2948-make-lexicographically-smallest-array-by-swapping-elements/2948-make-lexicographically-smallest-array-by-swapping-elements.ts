function lexicographicallySmallestArray(nums: number[], limit: number): number[] {
    const n = nums.length;

    // Step 1: Create array of [value, index] pairs
    const pairs: [number, number][] = nums.map((val, idx) => [val, idx]);

    // Step 2: Sort by value
    pairs.sort((a, b) => a[0] - b[0]);

    // Step 3: Group by the limit condition
    const groups: { start: number; end: number }[] = [];
    let start = 0;
    for (let i = 1; i <= n; i++) {
        if (i === n || pairs[i][0] - pairs[i - 1][0] > limit) {
            groups.push({ start, end: i - 1 });
            start = i;
        }
    }

    // Step 4: Process each group
    for (const { start, end } of groups) {
        const len = end - start + 1;
        const values: number[] = [];
        const indices: number[] = [];

        for (let i = start; i <= end; i++) {
            values.push(pairs[i][0]);
            indices.push(pairs[i][1]);
        }

        // Sort indices to assign values lexicographically
        indices.sort((a, b) => a - b);

        for (let i = 0; i < len; i++) {
            nums[indices[i]] = values[i];
        }
    }

    return nums;
}