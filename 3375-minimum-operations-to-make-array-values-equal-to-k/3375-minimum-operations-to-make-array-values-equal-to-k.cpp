class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
/*
        sort(nums.begin(), nums.end());
        int mini = nums[0];
        if (mini < k) return -1; // edge case
        
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > k) {
                cnt++;
                while (i + 1 < nums.size() && nums[i] == nums[i + 1]) 
                    i++;
            }
        }
        return cnt;
*/
/*
        unordered_map<int,int> mpp;
        for (int i : nums) 
            if (i < k) return -1;
            else if (i > k) mpp[i]++;
        return mpp.size();
*/
        int mini = *min_element(nums.begin(), nums.end());
        if (mini < k) return -1;
        
        unordered_set<int> st(nums.begin(), nums.end());
        return st.size() - (mini == k);
    }
};