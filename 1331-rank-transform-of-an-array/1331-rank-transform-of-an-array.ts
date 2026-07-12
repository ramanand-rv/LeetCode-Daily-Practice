function arrayRankTransform(arr: number[]): number[] {
    // sort
    const sorted = [...arr].sort((a, b) => a - b);
    
    // Remove duplicates
    const unique: number[] = [];
    for (const num of sorted) {
        if (unique.length === 0 || unique[unique.length - 1] !== num) {
            unique.push(num);
        }
    }
    
    // Binary search
    const lowerBound = (nums: number[], target: number): number => {
        let left = 0, right = nums.length;
        while (left < right) {
            const mid = Math.floor((left + right) / 2);
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;
    };
    
    // Replace with ranks
    const result: number[] = [];
    
    for (const num of arr) {
        const idx = lowerBound(unique, num);
        result.push(idx + 1);
    }
    
    return result;
}