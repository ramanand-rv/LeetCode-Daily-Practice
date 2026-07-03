function findSafeWalk(grid: number[][], health: number): boolean {
    const m = grid.length;
    const n = grid[0].length;
    const INF = Number.MAX_SAFE_INTEGER;

    class Deque {
        private data: Map<number, [number, number]> = new Map();
        private head: number = 0;
        private tail: number = 0;

        pushFront(val: [number, number]): void {
            this.data.set(--this.head, val);
        }

        pushBack(val: [number, number]): void {
            this.data.set(this.tail++, val);
        }

        popFront(): [number, number] | undefined {
            if (this.isEmpty()) return undefined;
            const val = this.data.get(this.head);
            this.data.delete(this.head); 
            this.head++;
            return val;
        }

        isEmpty(): boolean {
            return this.head === this.tail;
        }
    }

    const dist: number[][] = Array.from({ length: m }, () => Array(n).fill(INF));
    dist[0][0] = grid[0][0];

    const dq = new Deque();
    dq.pushBack([0, 0]);

    const dirs: number[][] = [
        [1, 0],
        [-1, 0],
        [0, 1],
        [0, -1],
    ];

    while (!dq.isEmpty()) {
        const item = dq.popFront();

        if (!item) continue;

        const [x, y] = item;

        for (const [dx, dy] of dirs) {
            const nx = x + dx;
            const ny = y + dy;

            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

            const w = grid[nx][ny];

            if (dist[x][y] + w < dist[nx][ny]) {
                dist[nx][ny] = dist[x][y] + w;

                if (w === 0) {
                    dq.pushFront([nx, ny]);
                } else {
                    dq.pushBack([nx, ny]);
                }
            }
        }
    }

    return dist[m - 1][n - 1] < health;
};