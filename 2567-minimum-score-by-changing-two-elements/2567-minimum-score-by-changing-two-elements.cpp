class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        // Track the 3 smallest and 3 largest values
        int s0 = INT_MAX, s1 = INT_MAX, s2 = INT_MAX;
        int l0 = 0, l1 = 0, l2 = 0; // assuming positive numbers

        for (int x : nums) {
            // Update 3 smallest
            if (x < s0) {
                s2 = s1; s1 = s0; s0 = x;
            } else if (x < s1) {
                s2 = s1; s1 = x;
            } else if (x < s2) {
                s2 = x;
            }

            // Update 3 largest
            if (x > l0) {
                l2 = l1; l1 = l0; l0 = x;
            } else if (x > l1) {
                l2 = l1; l1 = x;
            } else if (x > l2) {
                l2 = x;
            }
        }

        // Three ways to remove two elements:
        // 1. Remove two largest -> range = l2 - s0
        // 2. Remove two smallest -> range = l0 - s2
        // 3. Remove one smallest and one largest -> range = l1 - s1
        return min({l0 - s2, l2 - s0, l1 - s1});
    }
};