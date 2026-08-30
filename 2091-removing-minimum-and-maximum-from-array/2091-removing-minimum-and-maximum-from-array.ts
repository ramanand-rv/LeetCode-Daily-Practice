function minimumDeletions(nums: number[]): number {
    const n = nums.length;

    // Find indices of min and max
    let minIndex = 0;
    let maxIndex = 0;

    for (let i = 1; i < n; i++) {
        if (nums[i] < nums[minIndex]) minIndex = i;
        if (nums[i] > nums[maxIndex]) maxIndex = i;
    }

    const left = Math.min(minIndex, maxIndex);
    const right = Math.max(minIndex, maxIndex);

    // Remove both from the front
    const front = right + 1;

    // Remove both from the back
    const back = n - left;

    // Remove one from each side
    const frontBack = (left + 1) + (n - right);

    return Math.min(front, back, frontBack);
}