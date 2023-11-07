class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>>adj;
        for(auto &vec: flights){
            adj[vec[0]].push_back({vec[1], vec[2]});
        }
        queue<pair<int, int>>q;
        q.push({src, 0});
        
        vector<int>res(n, INT_MAX);
        
        while(!q.empty() && k-- >=0){
            int qSize = q.size();
            while(qSize--){
                auto [node, dist] = q.front(); q.pop();
                
                for(auto &[adjNode, adjDist] : adj[node]){
                    if(dist + adjDist < res[adjNode]){
                        res[adjNode] = dist + adjDist;
                        q.push({adjNode, dist + adjDist});
                    }
                }
            }
        }
        return res[dst] == INT_MAX ? -1 : res[dst];
    }
};