class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int best = 1, up = 1, down = 1;

        for (int i = 1; i < nums.size(); ++i) {
            // Extend increasing streak if current > previous, else reset to 1
            up = (nums[i - 1] < nums[i]) ? up + 1 : 1;

            // Extend decreasing streak if current < previous, else reset to 1
            down = (nums[i - 1] > nums[i]) ? down + 1 : 1;

            // Update the global maximum streak length
            best = max({best, up, down});
        }

        return best;
    }
};