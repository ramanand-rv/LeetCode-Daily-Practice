function maximumLength(nums: number[]): number {
    const freq = new Map();
    let ans = 0n;

    for (const x of nums) {
        const biNum = BigInt(x);
        freq.set(biNum, (freq.get(biNum) || 0n) + 1n);
    }

    for (const [key, val] of freq.entries()) {
        let curNum = key;

        if (curNum === 1n) {
            const oneLength = val % 2n === 0n ? val - 1n : val;
            if (oneLength > ans)
                ans = oneLength;
            continue;
        }
        let curLength = 0n;

        while (freq.has(curNum) && freq.get(curNum) >= 2n) {
            curLength += 2n;
            curNum *= curNum;
        }

        if (freq.has(curNum) && freq.get(curNum) === 1n)
            curLength++;
        else
            curLength--;

        if (curLength > ans)
            ans = curLength;
    }

    return Number(ans);

};