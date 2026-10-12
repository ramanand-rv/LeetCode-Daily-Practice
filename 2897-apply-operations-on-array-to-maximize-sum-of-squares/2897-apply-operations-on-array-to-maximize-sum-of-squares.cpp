class Solution {
public:
    int MOD = 1e9 + 7;

    vector<int> countBits(vector<int> nums) {
        vector<int> res(32, 0);

        for (auto& num : nums) {
            for (int b = 0; b < 32; b++) {
                if (num & (1 << b))
                    res[b]++;
            }
        }
        return res;
    }

    int maxSum(vector<int>& nums, int k) {
        auto bitCount = countBits(nums);

        long long ans = 0;
        while (k--) {
            long long cur = 0;

            for (int b = 0; b < 32; b++) {
                if (bitCount[b] > 0) {
                    bitCount[b]--;
                    cur = (cur | (1 << b));
                }
            }
            ans = (ans + (cur * cur)) % MOD;
        }
        return ans;
    }
};