function maxLength(nums: number[]): number {
    let best = 2;
    let left = 0;
    let product = 1;

    // Helper function to calculate GCD
    const gcd = (a: number, b: number): number => {
        while (b !== 0) {
            [a, b] = [b, a % b];
        }
        return a;
    };

    for (let right = 0; right < nums.length; right++) {
        const x = nums[right];
        
        // While the new number shares a factor with the current window's product
        while (gcd(product, x) > 1) {
            // Shrink the window from the left
            product = Math.floor(product / nums[left]);
            left++;
        }
        
        // Add the new number to the product
        product *= x;
        // Update the maximum length found
        best = Math.max(best, right - left + 1);
    }

    return best;
}