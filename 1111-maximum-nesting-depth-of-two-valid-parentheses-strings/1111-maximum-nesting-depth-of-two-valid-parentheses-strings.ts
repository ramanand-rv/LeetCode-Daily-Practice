function maxDepthAfterSplit(seq: string): number[] {
    let depth = 0;
    const ans: number[] = [];

    for (const ch of seq) {
        if (ch === '(') {
            depth++;
            ans.push(depth % 2);
        } else {
            ans.push(depth % 2);
            depth--;
        }
    }

    return ans;
}