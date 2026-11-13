function countNonDecreasingSubarrays(nums: number[], k: number): number {
    const n = nums.length;
    const starts: number[] = new Array(n).fill(0);
    let head = n, tail = n; // deque range [head, tail)
    let r = n - 1;
    let ans = 0, water = 0;

    // Process each left endpoint from right to left
    for (let l = n - 1; l >= 0; --l) {
        const x = nums[l];

        // Flood plateaus to the right that are <= x
        while (head < tail && nums[starts[head]] <= x) {
            const s = starts[head++]; // pop front plateau
            const end = head < tail ? starts[head] : r + 1;
            water += (x - nums[s]) * (end - s);
        }

        // New plateau starts at l
        starts[--head] = l;

        // Shrink window from right while water > k
        while (water > k) {
            // The bar at r belongs to the last plateau
            water -= nums[starts[tail - 1]] - nums[r];
            // If the last plateau is only index r, remove it
            if (starts[tail - 1] === r) {
                --tail;
            }
            --r;
        }

        // All subarrays ending at <= r starting at l are good
        ans += r - l + 1;
    }
    return ans;
}