function shortestBeautifulSubstring(s: string, k: number): string {
    const pos: number[] = [];

    // Store positions of all 1s
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '1') {
            pos.push(i);
        }
    }

    // Not enough 1s
    if (pos.length < k) return "";

    let ans = "";

    // Check every consecutive group of k ones
    for (let i = 0; i + k - 1 < pos.length; i++) {
        const start = pos[i];
        const end = pos[i + k - 1];
        const cur = s.substring(start, end + 1);

        if (ans === "" ||
            cur.length < ans.length ||
            (cur.length === ans.length && cur < ans)) {
            ans = cur;
        }
    }

    return ans;
}