#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Since we can ONLY increment elements, we cannot decrease the maximum
        // element. Therefore, the optimal target value X that all elements must
        // reach is max(nums).

        // The number of moves to convert an element `x` to `X` is (X - x).
        // Total moves = sum(X - x) for all x in nums.
        // This simplifies to: n * X - sum(nums).

        int n = nums.size();
        int max_val = *max_element(nums.begin(), nums.end());
        long long sum_val = accumulate(nums.begin(), nums.end(), 0LL);

        return static_cast<int>(n * max_val - sum_val);
    }
};