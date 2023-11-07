class Solution {
public:
//     Using BFS + Djikstra
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         unordered_map<int, vector<pair<int, int>>>adj;
//         for(auto &vec: flights){
//             adj[vec[0]].push_back({vec[1], vec[2]});
//         }
//         queue<pair<int, int>>q;
//         q.push({src, 0});
        
//         vector<int>res(n, INT_MAX);
        
//         while(!q.empty() && k-- >=0){
//             int qSize = q.size();
//             while(qSize--){
//                 auto [node, dist] = q.front(); q.pop();
                
//                 for(auto &[adjNode, adjDist] : adj[node]){
//                     if(dist + adjDist < res[adjNode]){
//                         res[adjNode] = dist + adjDist;
//                         q.push({adjNode, dist + adjDist});
//                     }
//                 }
//             }
//         }
//         return res[dst] == INT_MAX ? -1 : res[dst];
//     }
    
    
    
    
//     TLE due to negative path using Dijkstra. Hence use Bellman Ford Algo, 47/53
// int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//     unordered_map<int, vector<pair<int, int>>>adj;
//     for(auto &vec: flights) adj[vec[0]].push_back({vec[1], vec[2]});
    
//     vector<int>res(n, INT_MAX);
//     res[src]=0;
    
//     priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
// //     {dist, node, stops}
//     pq.push({0, src, k+1});
    
//     while( !pq.empty() ){
//         auto cur = pq.top(); pq.pop();
//         int dist = cur[0], node = cur[1], stops = cur[2];
//         if(node == dst) return dist;
        
//         if(stops > 0){
//             for(auto &[adjNode, adjDist] : adj[node])
//                 pq.push({dist + adjDist, adjNode, stops-1});
//         }   
//     }
//     return -1;
// }
    
    
    
//     Bellman Ford Algo
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int>dist(n, INT_MAX);
    dist[src] = 0;
    for(int i=0; i<=k; i++){
        vector<int>tmp(dist);
        for(auto &flight: flights){
            if(dist[flight[0]] != INT_MAX){
                tmp[flight[1]] = min(dist[flight[0]] + flight[2], tmp[flight[1]]);
            }
        }
        dist = tmp;
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}
};