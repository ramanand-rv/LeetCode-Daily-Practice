class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int>numCount(101);

        for(int i=nums.size()-1; i>=0; i--){
            numCount[nums[i]]++;
            if(numCount[nums[i]] > 1){
                return (i + 3) / 3;
            }
        }
        return 0;
    }
};