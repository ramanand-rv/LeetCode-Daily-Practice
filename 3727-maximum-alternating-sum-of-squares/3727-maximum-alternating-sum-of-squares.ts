function maxAlternatingSum(nums: number[]): number {
    const n = nums.length;
    const a = nums.map(x => x * x);
    a.sort((x, y) => x - y);

    let ans = 0;
    const k = Math.floor(n / 2);

    for (let i = 0; i < k; i++) ans -= a[i];
    for (let i = k; i < n; i++) ans += a[i];

    return ans;
}