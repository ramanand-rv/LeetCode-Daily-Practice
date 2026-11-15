class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1'000'000'007;
        long long even = 1, odd = 0, ans = 0;
        int parity = 0;

        for (int x : arr) {
            parity = (parity + x) & 1; // current prefix parity
            if (parity == 1) {
                ans += even; // pair with earlier even prefixes
                ++odd;
            } else {
                ans += odd; // pair with earlier odd prefixes
                ++even;
            }
            ans %= MOD;
        }
        return (int)ans;
    }
};