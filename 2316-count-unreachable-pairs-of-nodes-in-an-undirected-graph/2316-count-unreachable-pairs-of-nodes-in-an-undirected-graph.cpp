class Solution {
public:
//     vector<int>parent;
//     vector<int>rank;
    
    // Using DSU

//     int find(int node){
//         if(node == parent[node])
//             return node;
//         return parent[node] = find(parent[node]);
//     }

//     void Union(int x, int y){
//         int parent_x = find(x);
//         int parent_y = find(y);
//         if(parent_x == parent_y)
//             return;
//         if(rank[parent_x]>rank[parent_y])
//             swap(parent_x, parent_y);
//         parent[parent_x] = parent_y;
//         rank[parent_y]++;
//     }
//     long long countPairs(int n, vector<vector<int>>& edges) {
//         parent.resize(n);
//         rank.resize(n, 0);
//         long long unreachableNode = 0;
//         for(int i=0;i<n;i++)
//             parent[i] = i;
//         // Making components
//         for(auto node: edges){
//             Union(node[0], node[1]);
//         }
//         unordered_map<int, int>mp;
//         for(int i=0;i<n;i++){
//             int papaji = find(i);
//             mp[papaji]++;
//         }

//         // find count of components from mp
//         // result += size * (remaining - size)
//         long long result = 0;
//         long long remainingComponent = n;
//         for(auto it: mp){
//             long long size = it.second;
//             result += size * (remainingComponent - size);
//             remainingComponent -= size;
//         }

//         return result;
//     }


    
//     Using DFS
    // vector<bool>visited;
    // unordered_map<int, vector<int>>adj;
//     long long countPairs(int n, vector<vector<int>>& edges) {
//         visited.resize(n, false);
//         for(auto& e: edges){
//             int src = e[0];
//             int dst = e[1];
//             adj[src].push_back(dst);
//             adj[dst].push_back(src);
//         }
//         unordered_map<int, int>mp;
        
//         for(int node=0; node<n; node++){
//             int count = 0;
//             if(!visited[node]){
//                 dfs(node, visited, count);
//                 mp[node] = count;
//             }     
//         }
//         int remainingComp = n;
//         long long result = 0;
//         for(auto c: mp){
//             long long size = c.second;
//             result += size * (remainingComp - size);
//             remainingComp -= size;
//         }
//         return result;
//     }
    
//     void dfs(int node, vector<bool>& visited, int &count){
//         visited[node] = true;
//         count++;
//         for(auto& neighbour: adj[node]){
//             if(!visited[neighbour])
//                 dfs(neighbour, visited, count);
//         }
//     }



// Using BFS
    vector<bool>visited;
    unordered_map<int, vector<int>>adj;
    long long countPairs(int n, vector<vector<int>>& edges) {
        visited.resize(n, false);
        for(auto& e: edges){
            int src = e[0];
            int dst = e[1];
            adj[src].push_back(dst);
            adj[dst].push_back(src);
        }
        unordered_map<int, int>mp;
        for(int node =0; node<n;node++){
            int count = 0;
            if(!visited[node]){
                bfs(node, count);
                mp[node] = count;
            }
        }
        long long result = 0;
        long long remainingComp = n;
        for(auto c: mp){
            long long size = c.second;
            result += size * (remainingComp - size);
            remainingComp -= size;
        }
        return result;
    }

    void bfs(int node, int &count){
        queue<int>q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;
            for(int v: adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
};