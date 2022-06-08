class Solution {
public:
    int removePalindromeSub(string s) {
        string str = s;
        if(s.size()==0) return 0;
        reverse(str.rbegin(), str.rend());
        if(str==s) return 1;
        
        return 2;
    }
};