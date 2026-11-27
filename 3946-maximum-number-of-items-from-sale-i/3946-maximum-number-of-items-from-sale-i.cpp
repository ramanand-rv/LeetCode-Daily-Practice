class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> factors(n), prices(n);
        for (int i = 0; i < n; ++i) {
            factors[i] = items[i][0];
            prices[i] = items[i][1];
        }

        // Find the cheapest item to fill leftover budget
        int cheapest = *min_element(prices.begin(), prices.end());

        // best[m] stores max copies for 'm' budget
        vector<int> best(budget + 1);
        for (int m = 0; m <= budget; ++m) {
            best[m] = m / cheapest; // Baseline: only buying the cheapest item
        }

        for (int i = 0; i < n; ++i) {
            int factor = factors[i], price = prices[i];
            int gain = 0;
            // Calculate the gain (number of multiples)
            for (int other : factors) {
                if (other % factor == 0)
                    gain++;
            }

            // Only process if gain is better than spending money on the
            // cheapest item
            if (gain > price / cheapest) {
                // 0/1 Knapsack: iterate backwards to avoid reusing the same
                // first copy
                for (int m = budget; m >= price; --m) {
                    best[m] = max(best[m], best[m - price] + gain);
                }
            }
        }

        return best[budget];
    }
};