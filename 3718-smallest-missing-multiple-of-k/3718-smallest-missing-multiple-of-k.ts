function missingMultiple(nums: number[], k: number): number {
    const seen = new Set<number>();
    for (const x of nums) {
        if (x % k === 0) {
            seen.add(x / k);
        }
    }
    let i = 1;
    while (seen.has(i)) {
        i++;
    }
    return i * k;
}