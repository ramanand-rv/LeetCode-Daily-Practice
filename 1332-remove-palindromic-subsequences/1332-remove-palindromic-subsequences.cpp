class Solution {
public:
    int removePalindromeSub(string s) {
        string sReverse = s;
        if(s.size()==0) 
            return 0;
        reverse(sReverse.rbegin(), sReverse.rend());
        
        if(sReverse == s) 
            return 1;
        
        return 2;
    }
};