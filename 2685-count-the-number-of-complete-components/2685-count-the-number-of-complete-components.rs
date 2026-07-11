struct DSU {
    parent: Vec<usize>,
    size: Vec<usize>,
}

impl DSU {
    fn new(n: usize) -> Self {
        DSU {
            parent: (0..=n).collect(),
            size: vec![1; n + 1],
        }
    }

    fn find(&mut self, node: usize) -> usize {
        if self.parent[node] != node {
            self.parent[node] = self.find(self.parent[node]);
        }
        self.parent[node]
    }

    fn unite(&mut self, u: usize, v: usize) {
        let root_u = self.find(u);
        let root_v = self.find(v);

        if root_u == root_v {
            return;
        }

        if self.size[root_u] < self.size[root_v] {
            self.parent[root_u] = root_v;
            self.size[root_v] += self.size[root_u];
        } else {
            self.parent[root_v] = root_u;
            self.size[root_u] += self.size[root_v];
        }
    }

    fn get_size(&mut self, u: usize) -> usize {
        let root = self.find(u);
        self.size[root]
    }
}

impl Solution {
    pub fn count_complete_components(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut dsu = DSU::new(n);
        let mut degree = vec![0; n];

        // Union edges and track degrees
        for edge in &edges {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            dsu.unite(u, v);
            degree[u] += 1;
            degree[v] += 1;
        }

        // Group nodes by component root
        let mut components: std::collections::HashMap<usize, Vec<usize>> = 
            std::collections::HashMap::new();

        for i in 0..n {
            let root = dsu.find(i);
            components.entry(root).or_insert_with(Vec::new).push(i);
        }

        let mut complete_count = 0;

        // Check each component
        for (root, nodes) in components {
            let size = nodes.len();
            let mut is_complete = true;

            // In a complete component of size 'size', each node must have degree 'size - 1'
            for &node in &nodes {
                if degree[node] != size - 1 {
                    is_complete = false;
                    break;
                }
            }

            if is_complete {
                complete_count += 1;
            }
        }

        complete_count
    }
}