class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // dp[j] stores the minimum cost to reach step j
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0; // Starting at step 0 costs nothing
        
        for (int j = 1; j <= n; ++j) {
            // Try jumping from the previous 1, 2, or 3 steps
            for (int k = 1; k <= 3; ++k) {
                int i = j - k; // The step we are jumping from
                if (i >= 0) {
                    long long jump_cost = (long long)(j - i) * (j - i); // Squared jump distance
                    // Update min cost: cost to reach i + cost of step j + jump cost
                    dp[j] = min(dp[j], dp[i] + costs[j - 1] + jump_cost);
                }
            }
        }
        
        return (int)dp[n];
    }
};