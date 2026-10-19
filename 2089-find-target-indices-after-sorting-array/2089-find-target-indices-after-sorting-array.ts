function targetIndices(nums: number[], target: number): number[] {
    let left = 0;
    let right = 0;

    for (const x of nums) {
        if (x < target) left++;
        if (x <= target) right++;
    }

    const res: number[] = [];
    for (let i = left; i < right; i++) {
        res.push(i);
    }
    return res;
}