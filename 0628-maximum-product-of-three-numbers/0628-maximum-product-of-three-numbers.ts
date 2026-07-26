function maximumProduct(nums: number[]): number {
    let max1 = -1000, max2 = -1000, max3 = -1000;
    let min1 = 0, min2 = 0;

    for (const ele of nums) {
        if (ele >= max1) {
            max3 = max2;
            max2 = max1;
            max1 = ele;
        } else if (ele >= max2) {
            max3 = max2;
            max2 = ele;
        } else if (ele >= max3) {
            max3 = ele;
        }

        if (ele <= min1) {
            min2 = min1;
            min1 = ele;
        } else if (ele <= min2) {
            min2 = ele;
        }
    }

    return Math.max(max1 * max2 * max3, min1 * min2 * max1);
}