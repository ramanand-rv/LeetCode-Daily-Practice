class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int dp[4] = {0, 0, 0, 0}; // circular buffer

        for (int i = n - 1; i >= 0; i--) {
            int idx = i & 3; // i % 4

            // Take 1 stone
            int best = stoneValue[i] - dp[(i + 1) & 3];

            // Take 2 stones
            if (i + 1 < n) {
                best = max(best, stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) & 3]);
            }

            // Take 3 stones
            if (i + 2 < n) {
                best = max(best,
                    stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[(i + 3) & 3]
                );
            }

            dp[idx] = best;
        }

        int diff = dp[0];
        return diff > 0 ? "Alice" : diff < 0 ? "Bob" : "Tie";
    }
};