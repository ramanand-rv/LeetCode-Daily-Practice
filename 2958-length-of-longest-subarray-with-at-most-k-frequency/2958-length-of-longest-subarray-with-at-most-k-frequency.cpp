class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int i = 0, j = 0, n = nums.size();
        int res = 0;
        while (j < n) {
            freq[nums[j]]++;
            while (freq[nums[j]] > k) {
                freq[nums[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};