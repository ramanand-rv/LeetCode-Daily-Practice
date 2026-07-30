class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length(), res = 0;
        vector<int> v(26, 0);

        for (char c : word) v[c - 'a']++;
        
        sort(v.rbegin(), v.rend());

        for (int i = 0; i < size(v); i++) {
            if (v[i] == 0) break;

            if (i < 8) res += v[i];

            else if (i < 16) res += v[i] * 2;

            else if (i < 24) res += v[i] * 3;

            else res += v[i] * 4;
        }
        return res;
    }
};