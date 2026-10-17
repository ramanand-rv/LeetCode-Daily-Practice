function minSwaps(nums: number[]): number {
    const digitSum = (x: number): number => {
        let s = 0;
        while (x > 0) {
            s += x % 10;
            x = Math.floor(x / 10);
        }
        return s;
    };

    const n = nums.length;
    const keyed: [number, number][] = nums.map(x => [digitSum(x), x]);
    keyed.sort((a, b) => a[0] - b[0] || a[1] - b[1]);

    const rank = new Map<number, number>();
    for (let k = 0; k < n; k++) {
        rank.set(keyed[k][1], k);
    }

    const home: number[] = nums.map(x => rank.get(x)!);

    let swaps = 0;
    for (let i = 0; i < n; i++) {
        while (home[i] !== i) {
            const j = home[i];
            [home[i], home[j]] = [home[j], home[i]];
            swaps++;
        }
    }
    return swaps;
}