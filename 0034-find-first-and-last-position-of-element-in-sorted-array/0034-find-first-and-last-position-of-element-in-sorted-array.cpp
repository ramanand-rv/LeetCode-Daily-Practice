class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        ans.push_back(binSearch(nums, target, true));
        ans.push_back(binSearch(nums, target, false));
        return ans;
    }
    
    int binSearch(vector<int>& nums, int target, bool isFirst){
        int res=-1;
        int start=0, end=nums.size()-1;
        while(start <= end){
            int mid = start + (end-start) / 2;
            if(nums[mid] < target)
                start = mid +1;
            else if(nums[mid] > target)
                end = mid -1;
            else{
                res = mid;
                if(isFirst)
                    end = mid -1;
                else
                    start = mid +1;
            }
        }
        
        return res;
    }
};