class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;

        // Try every possible starting index
        for (int i = 0; i < n; i++) {
            int sum = 0;

            // Extend the subarray to the right
            for (int j = i; j < n; j++) {
                sum += nums[j];
                int len = j - i + 1;

                // Check if length is within bounds and sum is positive
                if (len >= l && len <= r && sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }

        // Return -1 if no valid subarray was found
        return ans == INT_MAX ? -1 : ans;
    }
};