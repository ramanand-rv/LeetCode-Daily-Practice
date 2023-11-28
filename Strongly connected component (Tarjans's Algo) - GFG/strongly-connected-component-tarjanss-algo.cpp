//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
	public:
	int timer =0;
	vector<vector<int>> res;
	
    void dfs(int node, vector<int>adj[], vector<int>& low,
    vector<int>& tin, vector<bool>& visited, stack<int>& st, vector<bool>& inStack)
    {
        visited[node] = true;
        low[node] = tin[node] = ++timer;
        st.push(node);
        inStack[node] = true;
        for(auto adjNode: adj[node]){
            
            if(!visited[adjNode]){
                dfs(adjNode, adj, low, tin, visited, st, inStack);
                low[node] = min(low[node], low[adjNode]);
            }
            
            else if(inStack[adjNode])
                low[node] = min(low[node], tin[adjNode]);
            }
            
            if(tin[node]==low[node]){
                vector<int>tmp;
                while(st.top() != node){
                    tmp.push_back(st.top());
                    inStack[st.top()] = false;
                    st.pop();
                }
                tmp.push_back(st.top());
                inStack[st.top()] = false;
                st.pop();
                sort(tmp.begin(), tmp.end());
                res.push_back(tmp);
        }
    }
	
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        vector<int>low(V, -1), tin(V, -1);
        vector<bool>inStack(V, false);
        vector<bool>visited(V, false);
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(!visited[i]) dfs(i, adj, low, tin, visited, st, inStack);
        }
        sort(res.begin(), res.end());
        return res;
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

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends