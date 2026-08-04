class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;
        bool present[101] = {};
        int minVal = INT_MAX, maxVal = INT_MIN;

        for (int ele : nums) {
            minVal = min(minVal, ele);
            maxVal = max(maxVal, ele);
            present[ele] = true;
        }

        for (int i = minVal; i <= maxVal; i++) {
            if (!present[i]) res.push_back(i);
        }
        return res;
    }
};