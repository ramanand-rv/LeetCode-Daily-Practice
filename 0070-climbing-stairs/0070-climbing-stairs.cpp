class Solution {
public:
/*
// Memoization
    int climbStairs(int n, int memo[]){
        if(n == 0 || n == 1) return 1;

        if(memo[n] == -1) memo[n] = climbStairs(n-1, memo) + climbStairs(n-2, memo);
        return memo[n];
    }

    int climbStairs(int n) {
        int memo[100];
        memset(memo, -1, sizeof(memo));
        return climbStairs(n, memo);
    }
*/

// Tabulation
    int climbStairs(int n){
        if(n == 0 || n == 1) return 1;
        
        vector<int>dp(n+1);
        dp[0] = dp[1] = 1;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

};