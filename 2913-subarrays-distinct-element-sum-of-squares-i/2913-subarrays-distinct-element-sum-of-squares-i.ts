function sumCounts(nums: number[]): number {
    const n = nums.length;
    let ans = 0;

    for (let l = 0; l < n; l++) {
        const seen = new Array(101).fill(false);
        let cnt = 0;
        for (let r = l; r < n; r++) {
            const x = nums[r];
            if (!seen[x]) {
                seen[x] = true;
                cnt++;
            }
            ans += cnt * cnt;
        }
    }

    return ans;
}