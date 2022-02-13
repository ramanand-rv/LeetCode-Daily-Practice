class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v = {{}};
        for(auto n:nums){
            int sz = v.size();
            for(int i=0; i<sz; i++){
                v.push_back(v[i]);
                v.back().push_back(n);
            }
        }
        
        return v;
    }
};