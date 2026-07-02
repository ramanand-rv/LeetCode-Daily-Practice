function maximumSafenessFactor(grid: number[][]): number {
    const n = grid.length;
    const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];

    // Step 1: Multi-Source BFS
    const dist = Array.from({ length: n }, () => Array(n).fill(Infinity));
    const q = [];

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                dist[i][j] = 0;
                q.push([i, j]);
            }
        }
    }

    let head = 0;
    while (head < q.length) {
        const [r, c] = q[head++];
        for (const [dr, dc] of dirs) {
            const nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] === Infinity) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push([nr, nc]);
            }
        }
    }

    // Step 2: Binary Search
    const canReach = (limit) => {
        if (dist[0][0] < limit) return false;

        const vis = Array.from({ length: n }, () => Array(n).fill(false));
        const queue = [[0, 0]];
        vis[0][0] = true;
        let head = 0;

        while (head < queue.length) {
            const [r, c] = queue[head++];
            if (r === n - 1 && c === n - 1) return true;

            for (const [dr, dc] of dirs) {
                const nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    !vis[nr][nc] && dist[nr][nc] >= limit) {
                    vis[nr][nc] = true;
                    queue.push([nr, nc]);
                }
            }
        }
        return false;
    };

    let low = 0, high = 2 * n, ans = 0;
    while (low <= high) {
        const mid = Math.floor((low + high) / 2);
        if (canReach(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
};
