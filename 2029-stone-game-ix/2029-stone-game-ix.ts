function stoneGameIX(stones: number[]): boolean {
    let cnt0 = 0;
    let cnt1 = 0;
    let cnt2 = 0;

    for (const x of stones) {
        const rem = x % 3;
        if (rem === 0) cnt0++;
        else if (rem === 1) cnt1++;
        else cnt2++;
    }

    if (cnt0 % 2 === 0) {
        return cnt1 > 0 && cnt2 > 0;
    }

    return Math.abs(cnt1 - cnt2) > 2;
}