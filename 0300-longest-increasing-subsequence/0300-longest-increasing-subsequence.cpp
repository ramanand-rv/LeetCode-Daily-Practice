class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>tails;

        for(auto &x: nums){
            auto posItr = lower_bound(tails.begin(),tails.end(), x);

            if(posItr == tails.end())
                tails.push_back(x);
            
            else
                *posItr = x;
        }
        return tails.size();

    }
};