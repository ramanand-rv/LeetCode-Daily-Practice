function minMoves(nums: number[]): number {
    const lo = Math.min(...nums);
    let moves = 0;
    for (const x of nums) moves += x - lo;
    return moves;
}