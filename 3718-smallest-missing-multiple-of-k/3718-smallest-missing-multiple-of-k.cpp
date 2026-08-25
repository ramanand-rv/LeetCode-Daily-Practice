class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (x % k == 0) {
                seen.insert(x / k);
            }
        }
        int i = 1;
        while (seen.count(i)) {
            ++i;
        }
        return i * k;
    }
};