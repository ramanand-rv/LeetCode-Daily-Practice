//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
//   162/165 TLE Using DFS.
    // vector<int> articulationPoints(int V, vector<int>adj[]) {
    //     vector<int>ans;
    //     vector<bool>isAP(V, false);
    //     for(int i=0;i<V;i++){
    //         vector<bool>visited(V, false);
    //         int component = 0;
    //         for(int j=0;j<V;j++){
    //             if(i != j && !visited[j]){
    //                 component++;
    //                 dfs(i, j, adj, visited);
    //             }
    //         }
    //         if(component > 1) isAP[i]=true;
    //     }
    //     for(int i=0;i<V;i++){
    //         if(isAP[i]) ans.push_back(i);
    //     }
    //     if(ans.size() < 1) ans.push_back({-1});
    //     return ans;
    // }
    
    // void dfs(int i, int src, vector<int>adj[], vector<bool>& visited){
    //     visited[src] = true;
    //     for(auto v: adj[src]){
    //         if(v != i && !visited[v])
    //             dfs(i, v, adj, visited);
    //     }
    // }
    
//  Using Tarjan's Algo:
int timer = 0;
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>low(V);
        vector<int>discTime(V);
        vector<bool>visited(V, false);
        vector<bool>ans(V, false);
        for(int i=0;i<V;i++)
            if(!visited[i]) dfs(i, -1, adj, low, discTime, visited, ans);
        vector<int>res;
        for(int i=0;i<V;i++) if(ans[i]) res.push_back(i);
        if(res.size()==0) return {-1};
        else return res;
    }
    
    void dfs(int node, int parent, vector<int>adj[], vector<int>& low, 
    vector<int>& discTime, vector<bool>& visited, vector<bool>& ans)
    {
        visited[node] = true;
        low[node] = discTime[node] = ++timer;
        int child = 0;
        for(auto adjNode: adj[node]){
            if(adjNode == parent) continue;
            if(!visited[adjNode]){
                dfs(adjNode, node, adj, low, discTime, visited, ans);   
                low[node] = min(low[adjNode], low[node]);
                if(low[adjNode] >= discTime[node] && parent != -1) ans[node] = true;
                child++;
            }
            else
                low[node] = min(low[node], discTime[adjNode]);
        }
        if(child > 1 && parent == -1)
            ans[node] = true;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends