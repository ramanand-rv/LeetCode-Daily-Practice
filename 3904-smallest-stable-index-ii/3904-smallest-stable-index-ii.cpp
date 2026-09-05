class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxSoFar = INT_MIN;
        int cand = 0, cMax = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            maxSoFar = max(maxSoFar, nums[i]);

            if (i == cand)
                cMax = maxSoFar;

            if (nums[i] < cMax - k)
                cand = i + 1;
        }

        return cand < n ? cand : -1;
    }
};