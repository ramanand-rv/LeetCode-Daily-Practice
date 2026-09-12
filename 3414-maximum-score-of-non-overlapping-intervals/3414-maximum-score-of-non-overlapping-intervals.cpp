class Solution {
public:
    using P = pair<long long, vector<int>>;

    vector<int> maximumWeight(vector<vector<int>>& a) {
        // stored in sorted order
        map<tuple<int, int, int>, int> originalIndex;
        for (int i = 0; i < a.size(); i++) {
            if (originalIndex.find({a[i][0], a[i][1], a[i][2]}) !=
                originalIndex.end()) {
                continue; // Skip Dublicate
            }
            originalIndex[{a[i][0], a[i][1], a[i][2]}] = i;
        }

        vector<tuple<int, int, int>> intervals;
        for (auto& [interval, index] : originalIndex) {
            intervals.push_back(interval);
        }

        int n = intervals.size();
        vector<int> nextIndex(n);

        // Next Valid Interval (non-overlapping)
        for (int i = 0; i < n; i++) {
            auto [left, right, weight] = intervals[i];
            nextIndex[i] = upper_bound(intervals.begin(), intervals.end(),
                                       make_tuple(right, INT_MAX, INT_MAX)) -
                           intervals.begin();
        }

        // dp[i][k] = best (negative weight, indices)
        // using intervals[i..n) with k picks left
        vector<vector<P>> dp(n + 1, vector<P>(5, {0, {}}));

        for (int i = n - 1; i >= 0; i--) {
            auto [left, right, weight] = intervals[i];
            int idx = originalIndex[{left, right, weight}];

            for (int k = 1; k <= 4; k++) {
                P skip = dp[i + 1][k];

                P take = dp[nextIndex[i]][k - 1];
                take.first -= weight; // ref : step 5 if you confuse
                take.second.push_back(idx);
                sort(take.second.begin(), take.second.end());

                dp[i][k] = min(skip, take);
            }
            // dp[i][0] stays {0, {}}
            // already correct from initialization
        }

        return dp[0][4].second;
    }
};