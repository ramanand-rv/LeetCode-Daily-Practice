class Solution {
public:

// Memoization
    int rob(int i, vector<int>&money, int memo[]){
        if(i < 0) return 0;
        if(memo[i] == -1) memo[i] = max(money[i] + rob(i-2, money, memo), rob(i-1, money, memo));
        return memo[i];
    }

    int rob(vector<int>& nums) {
        int memo[500];
        memset(memo, -1, sizeof(memo));
        return rob(nums.size()-1, nums, memo);
    }


};