#include <algorithm>
#include <climits>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost;

        // Maintain a sliding window of size x
        multiset<long long> window;
        for (int i = 0; i < x; ++i)
            window.insert(nums[i]);

        // mid points to the (h+1)-th smallest element (start of the larger
        // half)
        auto mid = next(window.begin(), x / 2);
        long long low_sum = accumulate(window.begin(), mid, 0LL);
        long long total_sum = accumulate(window.begin(), window.end(), 0LL);
        int odd = x % 2;

        // Cost = (sum of larger half) - (sum of smaller half)
        auto get_cost = [&]() {
            return (total_sum - low_sum - odd * (*mid)) - low_sum;
        };

        cost.push_back(get_cost());

        for (int i = x; i < n; ++i) {
            int in = nums[i];
            int out = nums[i - x];

            // Add new element
            window.insert(in);
            if (in < *mid) {
                low_sum += in - *prev(mid);
                --mid;
            }

            // Remove old element
            if (out < *mid) {
                low_sum += *mid - out;
                ++mid;
                window.erase(window.find(out));
            } else if (out == *mid) {
                mid = window.erase(mid);
            } else {
                window.erase(window.find(out));
            }

            total_sum += in - out;
            cost.push_back(get_cost());
        }

        // DP to select k non-overlapping windows
        // best[i] = min cost to fit current number of windows in nums[0..i)
        vector<long long> best(n + 1, 0);
        const long long INF = 1e18;

        for (int j = 0; j < k; ++j) {
            vector<long long> next_best(n + 1, INF);
            for (int i = x; i <= n; ++i) {
                // Option 1: skip current index (inherit previous best)
                // Option 2: place a window ending at i, so it starts at i-x
                next_best[i] = min(next_best[i - 1], best[i - x] + cost[i - x]);
            }
            best = move(next_best);
        }

        return best[n];
    }
};