//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<bool>visited(V, false);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!visited[i])
                dfs(i, adj, visited, st);
        }
        
        fill(visited.begin(), visited.end(), false);
        vector<int>transpose[V];
        for(int u=0;u<V;u++){
            for(auto v: adj[u])
                transpose[v].push_back(u);
        }
        
        int count=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!visited[node]){
                revDFS(node, transpose, visited);
                count++;
            }
        }
        return count;
    }
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st ){
        visited[u] = true;
        for(auto &v: adj[u]){
            if(!visited[v])
                dfs(v, adj, visited, st);
        }
        st.push(u);
    }
    
    void revDFS(int u, vector<int>transpose[], vector<bool>& visited){
        visited[u] = true;
        // nodes of each SCC can be printed here
        for(auto v: transpose[u]){
            if(!visited[v])
                revDFS(v, transpose, visited);
        }
    }
    
    
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends