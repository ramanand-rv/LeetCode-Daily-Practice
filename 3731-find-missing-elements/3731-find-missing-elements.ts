function findMissingElements(nums: number[]): number[] {
    const present: boolean[] = new Array(101).fill(false);
    let minVal = Infinity, maxVal = -Infinity;

    for (const ele of nums) {
        minVal = Math.min(minVal, ele);
        maxVal = Math.max(maxVal, ele);
        present[ele] = true;
    }

    const res: number[] = [];
    for (let i = minVal; i <= maxVal; i++) {
        if (!present[i]) res.push(i);
    }
    return res;
}