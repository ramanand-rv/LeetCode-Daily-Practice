class Solution {
public:
    string sbuild(string s){
        int a=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#') 
                a=max(0,--a);
            else s[a++]=s[i];
        }
        return s.substr(0,a);
    }
    
    bool backspaceCompare(string s, string t) {
        return sbuild(s) == sbuild(t);
    }
};