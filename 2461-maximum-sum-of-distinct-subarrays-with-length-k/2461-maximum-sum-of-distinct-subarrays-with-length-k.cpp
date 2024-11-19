class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0, curwinsize = 0;
        unordered_set<int>st;
        
        int i=0, j=0;
        while(j<n){
            while(st.count(nums[j])){
                curwinsize -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            
            curwinsize += nums[j];
            st.insert(nums[j]);
            
            if(j-i+1 == k){
                res = max(res, curwinsize);
                curwinsize -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};