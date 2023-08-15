//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V, false);
        vector<bool>inRec(V, false);
        
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(i, adj, visited, inRec)){
               return true;
            }
        }
        
        return false;
    }
    
    bool dfs(int u, vector<int>adj[], vector<bool>&visited, vector<bool>&inRec){
        visited[u] = true;
        inRec[u] = true;
       
        for(int &v: adj[u]){
            if(!visited[v] && dfs(v, adj, visited, inRec)){
                return true;
            }
            else if(inRec[v]){
                return true;
            }
        }
        inRec[u] = false;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends