function gcd(a: number, b: number): number {
    while (b !== 0) {
        [a, b] = [b, a % b];
    }
    return a;
}

function findGCD(nums: number[]): number {
    const mn = Math.min(...nums);
    const mx = Math.max(...nums);
    return gcd(mn, mx);
}