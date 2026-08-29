class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> pairs; // {value, original_index}
        pairs.reserve(n);

        for (int i = 0; i < n; i++) {
            pairs.push_back({nums[i], i});
        }

        // Sort by value
        sort(pairs.begin(), pairs.end());

        // Group by limit condition
        vector<pair<int, int>> groups; // {start, end} indices in pairs array
        int start = 0;
        for (int i = 1; i <= n; i++) {
            if (i == n || pairs[i].first - pairs[i - 1].first > limit) {
                groups.push_back({start, i - 1});
                start = i;
            }
        }

        // Process each group
        for (auto [s, e] : groups) {
            int len = e - s + 1;
            vector<int> values(len);
            vector<int> indices(len);

            // Extract values and original indices
            for (int i = s, j = 0; i <= e; i++, j++) {
                values[j] = pairs[i].first;
                indices[j] = pairs[i].second;
            }

            // Sort indices to assign values in left‑to‑right order
            sort(indices.begin(), indices.end());

            for (int i = 0; i < len; i++) {
                nums[indices[i]] = values[i];
            }
        }

        return nums;
    }
};