class DSU:
    def __init__(self, n: int):
        self.parent = list(range(n + 1))
        self.size = [1] * (n + 1)

    def find(self, node: int) -> int:
        if self.parent[node] != node:
            self.parent[node] = self.find(self.parent[node])
        return self.parent[node]

    def unite(self, u: int, v: int) -> None:
        root_u = self.find(u)
        root_v = self.find(v)

        if root_u == root_v:
            return

        if self.size[root_u] < self.size[root_v]:
            root_u, root_v = root_v, root_u

        self.parent[root_v] = root_u
        self.size[root_u] += self.size[root_v]

    def get_size(self, u: int) -> int:
        return self.size[self.find(u)]


class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        dsu = DSU(n)
        degree = [0] * n

        # Union edges and track degrees
        for u, v in edges:
            dsu.unite(u, v)
            degree[u] += 1
            degree[v] += 1

        # Group nodes by component root
        components = {}
        for i in range(n):
            root = dsu.find(i)
            if root not in components:
                components[root] = []
            components[root].append(i)

        complete_count = 0

        # Check each component
        for root, nodes in components.items():
            size = len(nodes)
            is_complete = True

            # In a complete component of size 'size', each node must have degree 'size - 1'
            for node in nodes:
                if degree[node] != size - 1:
                    is_complete = False
                    break

            if is_complete:
                complete_count += 1

        return complete_count