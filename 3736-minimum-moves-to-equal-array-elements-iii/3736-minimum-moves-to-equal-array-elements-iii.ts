function minMoves(nums: number[]): number {
    // Since we can ONLY increment elements, we cannot decrease the maximum element.
    // Therefore, the optimal target value X that all elements must reach is max(nums).

    // The number of moves to convert an element `x` to `X` is (X - x).
    // Total moves = sum(X - x) for all x in nums.
    // This simplifies to: n * X - sum(nums).

    const n = nums.length;
    const maxVal = Math.max(...nums);

    // Calculate the sum of all elements in the array
    const sumVal = nums.reduce((acc, curr) => acc + curr, 0);

    return n * maxVal - sumVal;
}