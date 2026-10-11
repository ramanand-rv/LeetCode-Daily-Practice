function sumOfSquares(nums: number[]): number {
    let n: number = nums.length;
    let sum: number = 0;

    for (let i = 1; i <= n; i++) {
        if (n % i == 0) {
            sum += nums[i - 1] * nums[i - 1];
        }
    }
    return sum;
};