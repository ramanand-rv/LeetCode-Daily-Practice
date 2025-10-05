class Solution {
public:
/*
// Tabulation
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n <= 2) return 1;

        vector<int>dp(n+1);
        dp[0] = 0; dp[1] = 1; dp[2] = 1;

        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
*/


    int tribonacci(int n, int memo[]){
        if(n == 0) return 0;
        if(n <= 2) return 1;

        if(memo[n] == -1) memo[n] = tribonacci(n-1, memo) + tribonacci(n-2, memo) + tribonacci(n-3, memo);

        return memo[n];
    }

    int tribonacci(int n){
        int memo[100];
        memset(memo, -1, sizeof(memo));

        return tribonacci(n, memo);
    }
};