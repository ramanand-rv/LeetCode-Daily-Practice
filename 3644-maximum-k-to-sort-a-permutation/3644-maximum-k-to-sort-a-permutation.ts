function sortPermutation(nums: number[]): number {
    let k = -1; // all bits set (in 32-bit two's complement)
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== i) {
            k &= nums[i];
            if (k === 0) return 0; // AND can only lose bits
        }
    }
    return Math.max(k, 0); // if nothing misplaced, k stays -1 -> 0
}