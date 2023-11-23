class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        vector<int> low(n), tin(n);
        vector<bool> visited(n, false);
        int timer = 1;
        for(auto &c: connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        
        vector<vector<int>>bridge;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i, -1, adj, bridge, visited, low, tin, timer);
            }
        }
        return bridge;
    }
    
    void dfs(int u, int parent, vector<vector<int>>& adj, 
            vector<vector<int>>& bridge, vector<bool>&visited,
            vector<int>&low, vector<int>&tin, int& timer)
    {
        visited[u] = true;
        low[u] = tin[u] = timer++;
        for(auto v: adj[u]){
            if(v == parent) continue;
            if(!visited[v]){
                dfs(v, u, adj, bridge, visited, low, tin, timer);
                low[u] = min(low[u], low[v]);
                if(low[v] > tin[u])
                    bridge.push_back({v, u});
            }
            else{
                low[u] = min(low[u], low[v]);
            }
        }
    }
};


























class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        disc = vector<int>(n);
        low = vector<int>(n);
        for (auto conn : connections) {
            edgeMap[conn[0]].push_back(conn[1]);
            edgeMap[conn[1]].push_back(conn[0]);
        }
        dfs(0, -1);
        return ans;
    }
    void dfs(int curr, int prev) {
    disc[curr] = low[curr] = time++;    
        for (int next : edgeMap[curr]) {
            if (disc[next] == 0) {
                dfs(next, curr);
                low[curr] = min(low[curr], low[next]);
            } else if (next != prev)
                low[curr] = min(low[curr], disc[next]);
            if (low[next] > disc[curr]) 
                ans.push_back({curr, next});
        }
    }
private:
    vector<int> disc{0}, low{0};
    int time = 1;
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> edgeMap;
};
