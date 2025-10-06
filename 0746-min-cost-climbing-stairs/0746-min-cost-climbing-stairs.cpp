class Solution {
public:
/*
// Memoization
    int minCost(int i, vector<int>&cost, int memo[]){
        if(i >= cost.size()) return 0;

        if(memo[i] == -1) memo[i] = cost[i] + min(minCost(i+1, cost, memo), minCost(i+2, cost, memo));
        return memo[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int memo[1010];
        memset(memo, -1, sizeof(memo));

        int n = cost.size();
        return min(minCost(0, cost, memo), minCost(1, cost, memo));
    }
*/

    int minCostClimbingStairs(vector<int>& cost){
        int n = cost.size();
        vector<int>dp(n+10);

        dp[0] = cost[0]; dp[1] = cost[1]; 

        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);
    }

};