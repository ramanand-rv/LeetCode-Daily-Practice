class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() <= k) return "0";
        if(k==0) return num;
        
        string res = "";
        stack<char>s;
        
        s.push(num[0]);
        
        for(int i=1;i<num.size();i++){
            while( k>0 && !s.empty() && num[i] < s.top()){
                k--;
                s.pop();
            }
            s.push(num[i]);
            
            while(s.size() ==1 && num[i]=='0')
                s.pop();
        }
        
        while(k && !s.empty()){
            k--;
            s.pop();
        }
        
        while(!s.empty()){
            res+= s.top();
            s.pop();
        }
        
        reverse(res.begin(), res.end());
        
         return (res.size()== 0) ? "0" : res;
    }
};