//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   // stack<int>st;
	   // vector<bool>visited(V, false);
	   // for(int i=0;i<V;i++){
	   //     if(!visited[i]){
	   //        // dfs(i, adj, visited, st);
	   //     }
	   // }
	    vector<int>res;
	   // while(!st.empty()){
	   //     res.push_back(st.top());
	   //     st.pop();
	   // }
	   // return res;
	   
	   // Kahn's algo
	   vector<int>inDeg(V, 0);
	   for(int u=0;u<V;u++){
	       for(int &v: adj[u]){
	           inDeg[v]++;
	       }
	   }
	   
	   queue<int>q;
	   for(int i=0;i<V;i++){
	       if(inDeg[i]==0){
	           q.push(i);
	       }
	   }
	   
	   while(!q.empty()){
	       int u = q.front();
	       q.pop();
	       res.push_back(u);
	       
	       for(int &v: adj[u]){
               if(--inDeg[v] ==0){
                   q.push(v);
               }
	       }
	   }
	   
	   return res;
	}
	

	
// 	void dfs(int u, vector<int>adj[], vector<bool>&visited, stack<int>&st){
// 	    visited[u] = true;
// 	    for(int &v: adj[u]){
// 	        if(!visited[v]){
// 	            dfs(v, adj, visited, st);
// 	        }
// 	    }
// 	    st.push(u);
// 	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends