class Solution {
public:
    bool isSubsequence(string &s, string &t) {
        int m = s.size();
        int n = t.size();
        bool res;
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }
        
        if(i==m)
            return true;
        return false;

    }
};