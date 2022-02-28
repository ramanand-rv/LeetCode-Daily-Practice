class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector < string> res;
        
        if(n == 0)
            return res;
        
        int left = 0, right = 0;
        
        while(right < n)
        {
            while(right + 1 < n && nums[right]+1 == nums[right+1])
                right++;
            
            string str = to_string(nums[left]);
            if(left != right)
                str += "->" + to_string(nums[right]);

            res.push_back(str);
            
            left = right = right + 1;
        }
        
        return res;
    }
};