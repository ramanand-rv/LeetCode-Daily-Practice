function minMoves2(nums: number[]): number {
    const n = nums.length;
    const k = Math.floor(n / 2);
    let lo = 0, hi = n - 1;

    while (lo < hi) {
        // Pick a random pivot to avoid worst-case O(n^2)
        const pivot = nums[lo + Math.floor(Math.random() * (hi - lo + 1))];
        let lt = lo, gt = hi, i = lo;

        // 3-way partition (Dutch National Flag)
        while (i <= gt) {
            if (nums[i] < pivot) {
                [nums[lt], nums[i]] = [nums[i], nums[lt]];
                lt++;
                i++;
            } else if (nums[i] > pivot) {
                [nums[i], nums[gt]] = [nums[gt], nums[i]];
                gt--;
            } else {
                i++;
            }
        }

        // Narrow down the search space
        if (k < lt) hi = lt - 1;
        else if (k > gt) lo = gt + 1;
        else break; // k is within the equal block, median found
    }

    const median = nums[k];
    let res = 0;
    for (const x of nums) {
        res += Math.abs(x - median);
    }
    return res;
}