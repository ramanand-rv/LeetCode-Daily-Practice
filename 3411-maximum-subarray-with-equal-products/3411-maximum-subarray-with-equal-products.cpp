class Solution {
public:
    int maxLength(vector<int>& nums) {
        int best = 2;
        int left = 0, product = 1;

        for (int right = 0; right < nums.size(); ++right) {
            int x = nums[right];

            // While the new number shares a factor with the current window's
            // product
            while (gcd(product, x) > 1) {
                // Shrink the window from the left
                product /= nums[left++];
            }

            // Add the new number to the product
            product *= x;
            // Update the maximum length found
            best = max(best, right - left + 1);
        }

        return best;
    }
};