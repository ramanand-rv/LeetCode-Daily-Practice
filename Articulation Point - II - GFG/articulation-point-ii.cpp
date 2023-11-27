//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    int timer =0;
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<bool>visited(V, false);
        vector<int>low(V);
        vector<int>tin(V);
        vector<bool>mark(V, false);
        for(int i=0;i<V;i++){
            if(!visited[i]) dfs(i, -1, adj, low, tin, visited, mark);
        }
        vector<int>res;
        for(int i=0;i<V;i++){
            if(mark[i]) res.push_back(i);
        }
        if(res.size()==0) return {-1};
        return res;
    }
    
    void dfs(int node, int parent, vector<int>adj[], vector<int>& low, vector<int>& tin, vector<bool>& visited, vector<bool>& mark){
        visited[node] = true;
        int child = 0;
        low[node] = tin[node] = ++timer;
        for(auto adjNode: adj[node]){
            if(adjNode==parent) continue;
            if(!visited[adjNode]){
                child++;
                dfs(adjNode, node, adj, low, tin, visited, mark);
                low[node] = min(low[node], low[adjNode]);
                if(low[adjNode] >= tin[node] && parent != -1) mark[node] = true;
            }
            else
                low[node] = min(low[node], tin[adjNode]);
        }
        if(child>1 && parent==-1) mark[node] = true;
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