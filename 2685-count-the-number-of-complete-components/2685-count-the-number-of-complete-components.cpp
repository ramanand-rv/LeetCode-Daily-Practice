class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;

        if (size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];
    }

    int getSize(int u) {
        return size[find(u)];
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        vector<int> degree(n, 0);

        // Union edges and track degrees
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            dsu.unite(u, v);
            degree[u]++;
            degree[v]++;
        }

        // Group nodes by component root
        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; i++) {
            components[dsu.find(i)].push_back(i);
        }

        int completeCount = 0;

        // Check each component
        for (const auto& [root, nodes] : components) {
            int size = nodes.size();
            bool isComplete = true;

            // In a complete component of size 'size', each node must have degree 'size - 1'
            for (int node : nodes) {
                if (degree[node] != size - 1) {
                    isComplete = false;
                    break;
                }
            }

            if (isComplete) {
                completeCount++;
            }
        }

        return completeCount;
    }
};