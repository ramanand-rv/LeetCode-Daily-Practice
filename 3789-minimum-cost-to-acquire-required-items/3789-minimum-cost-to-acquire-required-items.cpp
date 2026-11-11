class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // Use 64-bit to prevent overflow
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;
        
        // We can cover min(need1, need2) units with a type-3 item
        long long pairs = min(n1, n2);
        
        // For each pair, choose the cheaper option: type-3 OR type-1 + type-2
        long long costPairs = pairs * min(cb, c1 + c2);
        
        // Remaining units of each type after covering the pairs
        long long rem1 = n1 - pairs;
        long long rem2 = n2 - pairs;
        
        // Cover remaining units with either their specific type OR a type-3 item
        long long costRem = rem1 * min(c1, cb) + rem2 * min(c2, cb);
        
        return costPairs + costRem;
    }
};