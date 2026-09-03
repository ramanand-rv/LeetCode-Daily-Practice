function uniformArray(nums: number[]): boolean {
    let mn = Infinity;
    let oddCnt = 0;

    for (const x of nums) {
        if (x < mn) mn = x;
        if (x % 2 === 1) oddCnt++;
    }

    return (mn % 2 === 1) || (oddCnt === 0);
};