function gcdSum(nums: number[]): number {
    const n = nums.length;
    const a: number[] = new Array(n);
    let mx = 0;

    for (let i = 0; i < n; i++) {
        mx = Math.max(mx, nums[i]);
        a[i] = gcd(nums[i], mx);
    }

    a.sort((x, y) => x - y);

    let ans = 0;
    let l = 0, r = n - 1;
    
    while (l < r) {
        ans += gcd(a[l], a[r]);
        l++;
        r--;
    }

    return ans;
}

// GCD
function gcd(a: number, b: number): number {
    while (b) { [a, b] = [b, a % b]; }
    return a;
}