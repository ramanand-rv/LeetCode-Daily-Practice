class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, k = 0;
        for(int right=1; right<nums.size(); right++){
            if(nums[left] != nums[right]){
                nums[++left] = nums[right];
                k++;
            }
        }
        return left+1;
    }
};