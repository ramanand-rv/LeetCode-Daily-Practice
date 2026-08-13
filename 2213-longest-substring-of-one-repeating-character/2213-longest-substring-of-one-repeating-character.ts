class Node {
    leftChar: string;
    rightChar: string;
    length: number;
    prefix: number;
    suffix: number;
    best: number;

    constructor(l: string, r: string, len: number, pre: number, suf: number, b: number) {
        this.leftChar = l;
        this.rightChar = r;
        this.length = len;
        this.prefix = pre;
        this.suffix = suf;
        this.best = b;
    }
}

function merge(left: Node, right: Node): Node {
    const res = new Node(
        left.leftChar,
        right.rightChar,
        left.length + right.length,
        left.prefix,
        right.suffix,
        Math.max(left.best, right.best)
    );

    // Prefix
    if (left.rightChar === right.leftChar && left.prefix === left.length) {
        res.prefix = left.length + right.prefix;
    }

    // Suffix
    if (left.rightChar === right.leftChar && right.suffix === right.length) {
        res.suffix = right.length + left.suffix;
    }

    // Best
    if (left.rightChar === right.leftChar) {
        res.best = Math.max(res.best, left.suffix + right.prefix);
    }

    return res;
}

function longestRepeating(s: string, queryCharacters: string, queryIndices: number[]): number[] {
    const n = s.length;
    const tree: Node[] = new Array(4 * n);

    function build(node: number, start: number, end: number) {
        if (start === end) {
            tree[node] = new Node(s[start], s[start], 1, 1, 1, 1);
            return;
        }
        const mid = (start + end) >> 1;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    function update(node: number, start: number, end: number, idx: number, ch: string) {
        if (start === end) {
            tree[node] = new Node(ch, ch, 1, 1, 1, 1);
            return;
        }
        const mid = (start + end) >> 1;
        if (idx <= mid) update(node * 2, start, mid, idx, ch);
        else update(node * 2 + 1, mid + 1, end, idx, ch);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    build(1, 0, n - 1);
    const ans: number[] = [];
    for (let i = 0; i < queryIndices.length; i++) {
        update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
        ans.push(tree[1].best);
    }
    return ans;
}