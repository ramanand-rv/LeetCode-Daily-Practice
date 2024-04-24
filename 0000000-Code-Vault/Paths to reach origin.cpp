// https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1







//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
int mod = 1e9+7;
    int solve(int x, int y,  vector<vector<int>>&dp){
        if(x<0 || y<0) return 0;
        
        if(x==0 && y==0) return 1;
        
        if(dp[x][y] != -1) return dp[x][y];
        
        int left = solve(x-1, y, dp);
        int up = solve(x, y-1, dp);
        
        return dp[x][y] = (left + up)%mod;
    }
    int ways(int x, int y)
    {

        // vector<vector<int>>dp(501, vector<int>(501, -1));
        // return solve(x, y, dp);
        
        
        x++; y++;
        vector<vector<int>>dp(x, vector<int>(y, 0));
       
        for(int i=0;i<x;i++) dp[i][0] =1;
        
        for(int i=0;i<y;i++) dp[0][i] =1;
        
        for(int i=1;i<x;i++){
            for(int j=1;j<y;j++){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            }
        }
        return dp[x-1][y-1];
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends
