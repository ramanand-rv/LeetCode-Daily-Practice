class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        // Case 1: k == n
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 2: k == 1
        if (k == 1) {
            int ans = -1;
            for (int x : nums) {
                if (freq[x] == 1) ans = max(ans, x);
            }
            return ans;
        }

        // Case 3: 1 < k < n
        // Only first and last can be candidates
        int first = nums[0];
        int last = nums[n - 1];

        if (first == last) return -1; // same value appears in two subarrays

        bool firstValid = (freq[first] == 1);
        bool lastValid  = (freq[last] == 1);

        if (firstValid && lastValid) return max(first, last);
        if (firstValid) return first;
        if (lastValid)  return last;
        return -1;
    }
};