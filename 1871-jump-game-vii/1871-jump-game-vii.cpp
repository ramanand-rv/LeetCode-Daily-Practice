class Solution {
public:
    bool canReach(string s, int minj, int maxj) {
        int reach = 0;
        int n = s.size();
        vector<bool>dp(n, false);
        dp[0] = true;
        
        for(int i=1; i<n; i++){
            if(i>=minj)
                reach += dp[i - minj];
            if(i>maxj)
                reach -= dp[i - maxj - 1];
            
            dp[i] = reach > 0 && s[i]=='0';
        }
        
        return dp[n-1];
    }
};