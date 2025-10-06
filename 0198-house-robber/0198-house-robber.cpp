class Solution {
public:
    int rob(int i, vector<int>&money, int memo[]){
        if(i >= money.size()) return 0;
        if(memo[i] == -1) memo[i] = money[i] + max(rob(i+2, money, memo), rob(i+3, money, memo));
        return memo[i];
    }

    int rob(vector<int>& nums) {
        int memo[500];
        memset(memo, -1, sizeof(memo));
        return max(rob(0, nums, memo), rob(1, nums, memo));
    }
};