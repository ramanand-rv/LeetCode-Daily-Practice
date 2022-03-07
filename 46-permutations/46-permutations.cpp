class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        permutation(nums, v, 0);
        return v;
    }
    
    void permutation(vector<int> nums, vector<vector<int>> &v, int i){
        if(i == nums.size())
            v.push_back(nums);
        else{
            for(int j =i; j<nums.size(); j++){
                swap(nums[i], nums[j]);
                permutation(nums, v, i+1);
            }
        }
    }
};