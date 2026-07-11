class DSU {
    parent: number[];
    size: number[];

    constructor(n: number) {
        this.parent = new Array(n + 1);
        this.size = new Array(n + 1).fill(1);

        for (let i = 0; i <= n; i++) {
            this.parent[i] = i;
        }
    }

    find(node: number): number {
        if (this.parent[node] !== node) {
            this.parent[node] = this.find(this.parent[node]);
        }
        return this.parent[node];
    }

    unite(u: number, v: number): void {
        const rootU = this.find(u);
        const rootV = this.find(v);

        if (rootU === rootV) return;

        if (this.size[rootU] < this.size[rootV]) {
            this.parent[rootU] = rootV;
            this.size[rootV] += this.size[rootU];
        } else {
            this.parent[rootV] = rootU;
            this.size[rootU] += this.size[rootV];
        }
    }

    getSize(u: number): number {
        return this.size[this.find(u)];
    }
}

function countCompleteComponents(n: number, edges: number[][]): number {
    const dsu = new DSU(n);
    const degree: number[] = new Array(n).fill(0);

    // Union edges and track degrees
    for (const [u, v] of edges) {
        dsu.unite(u, v);
        degree[u]++;
        degree[v]++;
    }

    // Group nodes by component root
    const components: Map<number, number[]> = new Map();
    for (let i = 0; i < n; i++) {
        const root = dsu.find(i);
        if (!components.has(root)) {
            components.set(root, []);
        }
        components.get(root)!.push(i);
    }

    let completeCount = 0;

    // Check each component
    for (const [root, nodes] of components) {
        const size = nodes.length;
        let isComplete = true;

        // In a complete component of size 'size', each node must have degree 'size - 1'
        for (const node of nodes) {
            if (degree[node] !== size - 1) {
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