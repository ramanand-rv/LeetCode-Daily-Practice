//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V, false);
        for(int i=0;i<V;i++){
            // if(!visited[i] && dfs(adj, i, visited, -1))
            //     return true;
            if(!visited[i] && bfs(adj, i, visited))
                return true;
        }
        return false;
    }
    
    // bool dfs(vector<int>adj[], int u, vector<bool>&visited, int parent){
    //     visited[u] = true;
    //     for(int &v: adj[u]){
    //         if(!visited[v]){
    //             if(dfs(adj, v, visited, u))
    //                 return true;
    //         }
    //         else if(parent != v)
    //             return true;
    //     }
        
    //     return false;
    // }
    
    bool bfs(vector<int>adj[], int node, vector<bool>&visited){
        queue<pair<int, int>>q;
        q.push({node, -1});
        visited[node] = true;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(int &v: adj[node]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push({v, node});
                }
                else if(v != parent)
                    return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends