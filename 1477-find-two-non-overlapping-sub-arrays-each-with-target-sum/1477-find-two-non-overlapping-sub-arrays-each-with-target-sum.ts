function minSumOfLengths(arr: number[], target: number): number {
    const n = arr.length;
    let res = n + 1;
    let sum = 0;
    let i = 0;

    // dp[j] = min length of a valid subarray ending before index j
    const dp: number[] = new Array(n + 1).fill(n);

    for (let j = 0; j < n; j++) {
        sum += arr[j];

        // Shrink window while sum exceeds target
        while (sum > target) {
            sum -= arr[i++];
        }

        dp[j + 1] = dp[j];

        if (sum === target) {
            const len = j - i + 1;
            // dp[i] is min length before index i (non‑overlapping)
            res = Math.min(res, len + dp[i]);
            dp[j + 1] = Math.min(dp[j], len);
        }
    }

    return res === n + 1 ? -1 : res;
}