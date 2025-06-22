class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> ump;

        for(int &num: nums){
            ump[num]++;
        }

        int n = nums.size();
        for(auto e: ump){
            if(e.second > (n/2)){
                return e.first;
            }
        }
        return 0;
    }
};