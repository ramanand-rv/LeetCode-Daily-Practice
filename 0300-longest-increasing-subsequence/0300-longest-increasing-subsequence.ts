function lengthOfLIS(nums: number[]): number {
    let tails = []

    for (const x of nums) {
        let low = 0;
        let high = tails.length;
        
        while (low < high) {

            let mid = low + ((high - low) >> 1);

            if (tails[mid] < x)
                low = mid + 1;
            else
                high = mid;
        }

        if (low == tails.length)
            tails.push(x);
        else
            tails[low] = x;
    }
    return tails.length;
};