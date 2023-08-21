//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	   // 0 -> Red
	   // 1 -> Blue
	    vector<int>color(V, -1);
	    int curCol = 1;
	    
	   // for(int i=0;i<V;i++){
	   //     if(color[i]==-1 && !dfs(i, adj, color, curCol)){
	   //         return false;
	   //     }
	   // }
	   
	   for(int i=0;i<V;i++){
	       if(color[i]== -1){
	           if(!bfs(i, adj, color, curCol)){
	               return false;
	           }
	       }
	   }
	    return true;
	}
	
	bool bfs(int node, vector<int>adj[], vector<int>&color, int curCol){
	    queue<int>q;
	    color[node] = curCol;
	    q.push(node);
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        for(int &neighbour: adj[node]){
	            if(color[node] == color[neighbour]){
	                return false;
	            }
	            if(color[neighbour] == -1){
	                color[neighbour] = 1 - color[node];
	                q.push(neighbour);
	            }
	        }
	    }
	    return true;
	}
	
	bool dfs(int node, vector<int>adj[], vector<int>&color, int curCol){
	    color[node] = curCol;
	    
	    for(int &neighbour: adj[node]){
	        if(color[node] == color[neighbour]){
	            return false;
	        }
	        if(color[neighbour]==-1){
	            int neighbourCol = 1 - curCol;
	            if(!dfs(neighbour, adj, color, neighbourCol)){
	                return false;
	            }
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