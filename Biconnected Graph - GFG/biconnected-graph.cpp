//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int biGraph(int arr[], int n, int e) {
        vector<int>adj[n];
        int i=0;
        while(i < e*2 ){
            int u = arr[i]; i++;
            int v = arr[i]; i++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            vector<bool>visited(n, false);
            int component =0;
            for(int j=0;j<n;j++){
                if(j != i && !visited[j]){
                    component++;
                    dfs(i, j, adj, visited);
                }
            }
            if(component > 1)
                return 0;
        }
        return 1;
    }
    void dfs(int i, int cur, vector<int>adj[], vector<bool>& visited){
        visited[cur] = true;
        for(auto v: adj[cur]){
            if(v != i && !visited[v])
                dfs(i, v, adj, visited);
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        cin>>n>>e;
        
        int arr[2*e];
        for(int i=0; i<2*e; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.biGraph(arr,n,e) << endl;
    }
    return 0;
}
// } Driver Code Ends