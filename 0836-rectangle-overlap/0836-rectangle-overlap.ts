function isRectangleOverlap(rec1: number[], rec2: number[]): boolean {
    const left = Math.max(rec1[0], rec2[0]);
    const right = Math.min(rec1[2], rec2[2]);
    const bottom = Math.max(rec1[1], rec2[1]);
    const top = Math.min(rec1[3], rec2[3]);
    return left < right && bottom < top;
}