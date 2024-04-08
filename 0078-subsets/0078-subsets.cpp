class Solution {
public:
    vector<vector<int>>res;
    void gen(vector<int>&s, int i, vector<int>& nums ){
        if(i == nums.size()) {
            res.push_back(s);
            return;
        }
        
        gen(s, i+1, nums);
        
        s.push_back(nums[i]);
        gen(s, i+1, nums);
        s.pop_back();
    } 
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>x;
        gen(x, 0, nums);
        return res;
    }
};