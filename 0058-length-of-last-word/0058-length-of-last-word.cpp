class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        int res = 0;
        
        while(ss>> word)
            res = word.size();
        
        return res;
    }
};