class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        unordered_map<int, vector<pair<int, int>>>adj;
        for(auto &vec: times){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back({v, w});
        }
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        set<pair<int, int>>pq;
        vector<int>result(n+1, INT_MAX);
        result[src] = 0;
        result[0] = 0;
        pq.insert({0, src});
        while(!pq.empty()){
            auto &it = *(pq.begin());
            int time = it.first;
            int node = it.second;
            pq.erase(it);
            
            for(auto &v: adj[node]){
                int adjTime = v.second;
                int adjNode = v.first;
                if(time + adjTime < result[adjNode]){
                    if(result[adjNode] != INT_MAX){
                        pq.erase({time+adjTime, adjNode});
                    }
                    result[adjNode] = time + adjTime;
                    pq.insert({time+adjTime, adjNode});
                }
            }
        }
        int res = INT_MIN;
        for(auto &t: result){
            if(t==INT_MAX)  return -1;
            res = max(t, res);
        }
        return res;
    }
};