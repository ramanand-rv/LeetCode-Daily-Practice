class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // Remove multiples
        sort(coins.begin(), coins.end());
        vector<long long> c;
        for (int x : coins) {
            bool ok = true;
            for (long long y : c) {
                if (x % y == 0) { ok = false; break; }
            }
            if (ok) c.push_back(x);
        }
        int n = c.size();

        // Precompute LCM for every subset mask
        vector<long long> lcm_mask(1 << n, 1);
        for (int mask = 1; mask < (1 << n); mask++) {
            int bit = __builtin_ctz(mask);
            int rest = mask ^ (1 << bit);
            lcm_mask[mask] = std::lcm(lcm_mask[rest], c[bit]);
        }

        auto count = [&](long long m) -> long long {
            long long total = 0;
            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = lcm_mask[mask];
                long long cnt = m / l;
                if (__builtin_popcount(mask) & 1) total += cnt;
                else total -= cnt;
            }
            return total;
        };

        long long lo = 1, hi = 1LL * k * c[0];
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            if (count(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};