https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') open++;
            if(s[i]==')') open--;
            if(open < 0) s[i]= '*', open++;
        }
        
        int close=0;
        for(int i=s.size()-1; i>=0;i--){
            if(s[i]==')') close++;
            if(s[i]=='(') close--;
            if(close < 0) s[i]='*', close++;
        }
        s.erase(remove(begin(s), end(s), '*'), end(s));
        return s;
    }
};
