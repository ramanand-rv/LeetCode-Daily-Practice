class Solution {
    long long nCr(int n, int r, int k) {
        long long res = 1;
        r = min(r, n - r);
        for (int i = 1; i <= r; i++) {
            res = res * (n - i + 1) / i;
            if (res > k)
                return k + 1LL;
        }
        return res;
    }

    long long ways(int n, vector<int>& f, int k) {
        long long total = 1;
        for (int i = 0; i < 26; i++) {
            total *= nCr(n, f[i], k);
            if (total > k)
                return k + 1LL;
            n -= f[i];
        }
        return total;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.size(), len = n / 2;
        vector<int> f(26, 0);
        for (char c : s)
            f[c - 'a']++;

        string str(n, ' ');
        // middle char
        for (int i = 0; i < 26; i++) {
            if (f[i] & 1)
                str[n / 2] = char('a' + i);
            f[i] /= 2;
        }

        long long total = ways(len, f, k);
        if (total < k)
            return "";

        for (int idx = 0; idx < len; idx++) {
            for (int i = 0; i < 26; i++) {
                if (f[i] == 0)
                    continue;
                f[i]--;
                long long possible = ways(len - idx - 1, f, k);
                if (possible >= k) {
                    str[idx] = char('a' + i);
                    break;
                } else {
                    k -= possible;
                    f[i]++;
                }
            }
        }

        for (int i = 0; i < len; i++) {
            str[n - 1 - i] = str[i];
        }
        return str;
    }
};