#include <vector>
using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> starts(n);  // deque of plateau start indices, left to right
        int head = n, tail = n; // empty deque [head, tail)
        int r = n - 1;          // right pointer of the window
        long long ans = 0, water = 0;

        // Process each left endpoint from right to left
        for (int l = n - 1; l >= 0; --l) {
            int x = nums[l];

            // Flood plateaus to the right that are <= x
            while (head < tail && nums[starts[head]] <= x) {
                int s = starts[head++]; // pop front plateau
                // End of this plateau: next plateau start, or r+1 if last
                int end = (head < tail) ? starts[head] : r + 1;
                water += 1LL * (x - nums[s]) * (end - s);
            }

            // New plateau starts at l
            starts[--head] = l;

            // Shrink window from right while water > k
            while (water > k) {
                // The bar at r belongs to the last plateau
                water -= nums[starts[tail - 1]] - nums[r];
                // If the last plateau has only index r, remove it
                if (starts[tail - 1] == r) {
                    --tail;
                }
                --r;
            }

            // All subarrays ending at <= r starting at l are good
            ans += r - l + 1;
        }
        return ans;
    }
};