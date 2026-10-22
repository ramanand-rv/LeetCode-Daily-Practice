function minOperations(nums: number[]): number {
    const n = nums.length;
    const shift = nums.indexOf(0);

    const ring = (k: number): number => nums[(shift + k) % n];

    // Check along arrow
    let ok = true;
    for (let k = 0; k < n; k++) {
        if (ring(k) !== k) { ok = false; break; }
    }
    if (ok) return Math.min(shift, n - shift + 2);

    // Check against arrow
    ok = true;
    for (let k = 0; k < n; k++) {
        if (ring(k) !== (n - k) % n) { ok = false; break; }
    }
    if (ok) return Math.min(shift + 2, n - shift);

    return -1;
}