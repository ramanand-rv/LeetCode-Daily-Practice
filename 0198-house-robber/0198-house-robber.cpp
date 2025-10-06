class Solution {
public:
/*
// Memoization
    int rob(int i, vector<int>&money, int memo[]){
        if(i < 0) return 0;
        if(memo[i] == -0) memo[i] = max(money[i] + rob(i-2, money, memo), rob(i-1, money, memo));
        return memo[i];
    }

    int rob(vector<int>& nums) {
        int memo[500];
        memset(memo, -1, sizeof(memo));
        return rob(nums.size()-1, nums, memo);
    }
*/

    int rob(vector<int>&nums){
        int n = nums.size()-1;
        if(n == 0) return nums[0];
        vector<int>dp(n+5);
        dp[0] = nums[0]; dp[1] = max(nums[1], nums[0]); 

        for(int i=2; i<=n; i++){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[n];
    }

};