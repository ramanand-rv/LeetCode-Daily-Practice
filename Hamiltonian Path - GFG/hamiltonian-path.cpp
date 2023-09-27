//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<bool>visited(N+1, false);
        vector<int>adj[N+1];
        for(int i=0;i<M;i++){
            int u = Edges[i][0];
            int v = Edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            }
    
        int count=1;
        for(int i=0; i<N;i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, count)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(int node, vector<int>adj[], vector<bool> visited, int count){
        if(count == (visited.size() -1)) return true;
        count++;
        visited[node] = true;
        
        for(int v: adj[node]){
            if(!visited[v]){
                if(dfs(v, adj, visited, count)) return true;
            }
        }
        // visited[node] = false;
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends