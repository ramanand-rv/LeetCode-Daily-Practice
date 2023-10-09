//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        vector<bool>visited(V, false);
        int count = 0;
        dfs(source, destination, adj, visited, count);
        return count;
    }
    
    void dfs(int src, int dst, vector<int>adj[], vector<bool>& visited, int &count){
        if(src == dst)
            count++;
        visited[src] = true;
        for(auto &v: adj[src]){
            if(!visited[v])
                dfs(v, dst, adj, visited, count);
        }
        visited[src] = false;
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
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends