//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  vector<int>parent;
  vector<int>rank;
  
  int find(int node){
      if(node == parent[node]) return node;
      return parent[node] = find(parent[node]);
  }
  
  void Union(int x, int y){
      int parent_x = find(x);
      int parent_y = find(y);
      if(parent_x == parent_y)  return;
      if(rank[parent_x] > rank[parent_y])   swap(rank[parent_x], rank[parent_y]);
      parent[parent_x] = parent_y;
      rank[parent_y]++;
  }
  
    int numProvinces(vector<vector<int>> &adj, int V) {
        parent.resize(V);
        rank.resize(V, 0);
        for(int i=0;i<V;i++){
            parent[i] = i;
        }
        
        for(int u=0; u<V;u++){
            for(int v=0;v<adj[u].size();v++){
                int parent_u = find(u);
                int parent_v = find(v);
                if(adj[u][v]==1 && parent_u != parent_v){
                    Union(u, v);
                }
            }
        }
        set<int>s;
        for(auto e: parent)
            s.insert(e);
            
        return s.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends