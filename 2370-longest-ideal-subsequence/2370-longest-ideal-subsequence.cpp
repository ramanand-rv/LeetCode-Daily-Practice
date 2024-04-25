class Solution {
public:
    int longestIdealString(string s, int k) {
//         Recursion + memo
        // vector<vector<int>>dp (s.size()+1,vector<int>(150,-1));
        // return lis(s, k, 0, 0, dp);
        
//         DP
        int dp[150] = {}, res = 0;
        
        for(auto &i: s){
            for(int j=i-k; j<=i+k;j++)
                dp[i] = max(dp[i], dp[j]);
            
            res = max(res, ++dp[i]);
        }
        return res;
    }
    
    int lis(string &s, int k, int idx, int prv, vector<vector<int>>&dp){
        if(idx>=s.size()) return 0;
        
        if(dp[idx][prv] != -1) return dp[idx][prv];
        
        int increasing = 0;
        int notIncreasing = 0;
        if(prv==0 || abs(s[idx] - prv) <= k){
            increasing = 1 + lis(s, k, idx+1, s[idx], dp);
        }
        
        notIncreasing = lis(s, k, idx+1, prv, dp);
        
        return dp[idx][prv] = max(increasing, notIncreasing);
         
    }
};