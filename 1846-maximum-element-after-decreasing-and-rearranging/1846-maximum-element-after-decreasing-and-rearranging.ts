function maximumElementAfterDecrementingAndRearranging(arr: number[]): number {
    const n = arr.length;

    arr.sort((a, b) => a - b);
/*

    arr[0] = 1;

    for (let i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1] + 1) {
            arr[i] = arr[i - 1] + 1;
        }
    }
    return arr.at(-1)
*/
    let target = 1;

    for(const v of arr){
        if(v >= target){
            target++;
        }
    }
    return target-1;
};