//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Max Heap
    // priority_queue<int, vector<int>>pq;
    
    // Min Heap
    // priority_queue<int, vector<int>>, greater<int>>pq
    
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex Source.


    
    // Using Min Heap
    // vector <int> dijkstra(int V, vector<vector<int>> adj[], int source)
    // {
    //     priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
    //     vector<int>result(V, INT_MAX);
        
    //     result[source] = 0;
    //     pq.push({0, source});
        
    //     while(!pq.empty()){
    //         int dist = pq.top().first;
    //         int node = pq.top().second;
    //         pq.pop();
            
    //         for(auto& v: adj[node]){
    //             int neighbourNode = v[0];
    //             int neighbourDist = v[1];
                
    //             if(dist + neighbourDist < result[neighbourNode]){
    //                 result[neighbourNode] = dist + neighbourDist;
    //                 pq.push({dist + neighbourDist, neighbourNode});
    //             }
    //         }
    //     }
    //     return result;
    // }
    
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int source){
        set<pair<int,int>>s;
        vector<int>result(V, INT_MAX);
        
        result[source] = 0;
        s.insert({0, source});
        
        while(!s.empty()){
            auto &it = *s.begin();
            int dist = it.first;
            int node = it.second;
            s.erase(it);
            
            for(auto &v: adj[node]){
                int neighbourNode = v[0];
                int neighbourDist = v[1];
                
                if(dist + neighbourDist < result[neighbourNode]){
                    if(result[neighbourNode] != INT_MAX){
                        s.erase({result[neighbourNode], neighbourNode});
                    }
                    result[neighbourNode] = dist + neighbourDist;
                    s.insert({dist + neighbourDist, neighbourNode});
                }
            }
        }
        return result;
    }
    
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends