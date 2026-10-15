class Solution {
public:
    int sumCounts(vector<int>& nums) {
        static bitset<101> seen;
        int n = nums.size();
        int ans = 0;
        for (int l = 0; l < n; l++) {
            seen.reset();
            int cnt = 0;
            for (int r = l; r < n; r++) {
                int x = nums[r];
                if (!seen[x]) {
                    seen[x] = 1;
                    cnt++;
                }
                ans += cnt * cnt;
            }
        }
        return ans;
    }
};