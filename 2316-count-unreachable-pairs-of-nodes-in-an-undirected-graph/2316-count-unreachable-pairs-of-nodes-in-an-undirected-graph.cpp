class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int node){
        if(node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        if(parent_x == parent_y)
            return;
        if(rank[parent_x]>rank[parent_y])
            swap(parent_x, parent_y);
        parent[parent_x] = parent_y;
        rank[parent_y]++;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);
        long long unreachableNode = 0;
        for(int i=0;i<n;i++)
            parent[i] = i;
        // Making components
        for(auto node: edges){
            Union(node[0], node[1]);
        }
        unordered_map<int, int>mp;
        for(int i=0;i<n;i++){
            int papaji = find(i);
            mp[papaji]++;
        }

        // find count of components from mp
        // result += size * (remaining - size)
        long long result = 0;
        long long remainingComponent = n;
        for(auto it: mp){
            long long size = it.second;
            result += size * (remainingComponent - size);
            remainingComponent -= size;
        }

        return result;
    }
};