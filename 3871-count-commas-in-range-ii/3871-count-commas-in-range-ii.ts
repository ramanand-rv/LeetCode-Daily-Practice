function countCommas(n: number): number {
    if (n <= 999) return 0;
    let total = 0;
    let start = 1000;
    while (start <= n) {
        total += n - start + 1;
        start *= 1000;
    }
    return total;
}