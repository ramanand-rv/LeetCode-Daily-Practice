function findTheDistanceValue(arr1: number[], arr2: number[], d: number): number {
    arr1.sort((a, b) => a - b);
    arr2.sort((a, b) => a - b);

    let ans = 0;
    let j = 0;

    for (const x of arr1) {
        // Advance j to the first element in arr2 that is >= x - d
        while (j < arr2.length && arr2[j] < x - d) {
            j++;
        }

        // If no such element exists, or it's strictly greater than x + d, x is valid
        if (j === arr2.length || arr2[j] > x + d) {
            ans++;
        }
    }

    return ans;
}