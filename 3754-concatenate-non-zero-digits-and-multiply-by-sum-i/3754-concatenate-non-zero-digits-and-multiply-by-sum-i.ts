function sumAndMultiply(n: number): number {
    let x = 0;
    let sum = 0;
    let len = 1;

    while (n !== 0) {
        x = (n % 10) * len + x;

        if (n % 10 !== 0) {
            len = len * 10;
        }

        sum += n % 10;

        n = Math.floor(n / 10);
    }

    return sum * x;
};