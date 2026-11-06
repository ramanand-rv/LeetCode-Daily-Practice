function countServers(n: number, logs: number[][], x: number, queries: number[]): number[] {
    // Sort logs by time (index 1)
    logs.sort((a, b) => a[1] - b[1]);

    // Pair queries with original indices and sort by time
    const q = queries.map((t, i) => [t, i]);
    q.sort((a, b) => a[0] - b[0]);

    const cnt = new Array(n + 1).fill(0);
    const ans = new Array(queries.length).fill(0);
    let l = 0, r = 0, active = 0;

    for (const [t, idx] of q) {
        // Add logs within time <= t
        while (r < logs.length && logs[r][1] <= t) {
            // If this server becomes active, increment active count
            if (++cnt[logs[r][0]] === 1) active++;
            r++;
        }

        // Remove logs strictly outside the window (time < t - x)
        while (l < r && logs[l][1] < t - x) {
            // If this server becomes inactive, decrement active count
            if (--cnt[logs[l][0]] === 0) active--;
            l++;
        }

        // Inactive servers = total servers - active servers
        ans[idx] = n - active;
    }

    return ans;
}