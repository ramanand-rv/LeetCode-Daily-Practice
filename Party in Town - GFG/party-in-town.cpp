//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int partyHouse(int N, vector<vector<int>> &adj){
        vector<int>maxDistFromCurr(1);
        int minDist = N;
        
        for(int i=1;i<=N;i++){
            maxDistFromCurr[0]=0;
            dfs(i, adj, -1, maxDistFromCurr, 0);
            minDist = min(minDist, maxDistFromCurr[0]);
        }
        return minDist;
    }
    
    void dfs(int u, vector<vector<int>>& adj, int parent,
    vector<int>& DistFromCurr, int currDist){
        DistFromCurr[0] = max(DistFromCurr[0], currDist);
        for(auto v: adj[u]){
            if(v != parent){
                dfs(v, adj, u, DistFromCurr, currDist+1);
            }
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}
// } Driver Code Ends