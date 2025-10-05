class Solution {
public:
/*
// Memoization
    int fibo(int n, int memo[]){
        if(n <= 1) return n;

        if(memo[n] == -1) memo[n] = fibo(n-1, memo) + fibo(n-2, memo);

        return memo[n];
    }

    int fib(int n) {
        int memo[100];
        memset(memo, -1, sizeof(memo));

        return fibo(n, memo);
    }
*/

/*
// Tabulation
    int fib(int n){
        if(n <= 1) return n;

        vector<int>dp(n+1);
        dp[0] = 0; 
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
*/

// Memory Optimization
    int fib(int n){
        if( n <= 1) return n;
        int curr = 1, prev = 0;

        for(int i=2; i<=n; i++){
            curr = curr + prev;
            prev = curr - prev;
        }
        return curr;
    }
};