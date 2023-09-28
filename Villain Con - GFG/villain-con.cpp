//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minColour(int N, int M, vector<int> mat[]) {
        vector<bool>visited(N, false);
        unordered_map<int, vector<int>>adj;
        for(int i=0;i<M;i++){
            int u = mat[i][0]-1;
            int v = mat[i][1]-1;
            adj[u].push_back(v);
        }
        vector<int>fill(N, 0);
        for(int i=0; i<N;i++){
            if(!visited[i]){
                int colr=0;
                dfs(i, adj, fill, visited);
            }
        }
        return (int) *max_element(fill.begin(), fill.end());
    }
    
    void dfs(int u, unordered_map<int, vector<int>>&adj, vector<int>&fill, vector<bool>& visited){
        visited[u] = true;
        int colr=0;
        for(auto v: adj[u]){
            if(!visited[v]){
                dfs(v, adj, fill, visited);
            }
            colr = max(colr, fill[v]);
        }
        fill[u] = colr+1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends