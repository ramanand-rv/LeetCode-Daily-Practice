//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V, false);

        for(int i=0;i<V;i++){
            // if(!visited[i] && isCycleDFS(adj, i, visited, -1))
                // return true;
            if(!visited[i] && isCycleBFS(adj, i, visited))
                return true;
        }
        return false;
    }
    
    bool isCycleBFS(vector<int>adj[], int node, vector<bool> &visited){
        queue<pair<int, int>>q;
        q.push({node, -1});
        visited[node] = true;
        
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int node = p.first;
            int parent = p.second;
            
            for(auto v:adj[node]){
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
    
    // bool isCycleDFS(vector<int>adj[], int &node, vector<bool>&visited, int parent){
    //     visited[node] = true;
    //     for(auto v: adj[node]){
    //         if(v==parent)   continue;
    //         if(visited[v])  return true;
    //         if(isCycleDFS(adj, v, visited, node))   return true;
    //     }
        
    //     return false;
    // }
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