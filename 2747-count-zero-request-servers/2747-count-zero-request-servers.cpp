class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        // Sort logs by request time
        sort(logs.begin(), logs.end(),
             [](const auto& a, const auto& b) { return a[1] < b[1]; });

        // Pair queries with their original indices and sort by time
        vector<pair<int, int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());

        vector<int> cnt(n + 1, 0), ans(queries.size());
        int l = 0, r = 0, active = 0;

        for (auto [t, i] : q) {
            // Add logs within time <= t
            while (r < logs.size() && logs[r][1] <= t) {
                // If this server becomes active, increment active count
                if (++cnt[logs[r][0]] == 1)
                    active++;
                r++;
            }

            // Remove logs strictly outside the window (time < t - x)
            while (l < r && logs[l][1] < t - x) {
                // If this server becomes inactive, decrement active count
                if (--cnt[logs[l][0]] == 0)
                    active--;
                l++;
            }

            // Inactive servers = total servers - active servers
            ans[i] = n - active;
        }

        return ans;
    }
};