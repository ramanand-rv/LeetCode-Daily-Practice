//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int>color(V, -1);
	    int curCol = 1;
	    for(int i=0; i<V; i++){
	        if(color[i]==-1 && !DFS(i, adj, color, curCol)){
	            return false;
	        }
	    }
	    
	    return true;
	}
	
	bool DFS(int curNode, vector<int>adj[], vector<int>& color, int curCol){
	    color[curNode] = curCol;
	    
	    for(auto &v: adj[curNode]){
	        if(color[curNode] == color[v])
	            return false;
            if(color[v]==-1){
                int colOfV = 1 - curCol;
                if(!DFS(v, adj, color, colOfV))
                    return false;
            }
	    }
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends