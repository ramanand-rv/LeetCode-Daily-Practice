class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int left = 0, right = 0;
        for (int x : nums) {
            if (x < target)
                left++;
            if (x <= target)
                right++;
        }

        vector<int> res(right - left);
        iota(res.begin(), res.end(), left);
        return res;
    }
};