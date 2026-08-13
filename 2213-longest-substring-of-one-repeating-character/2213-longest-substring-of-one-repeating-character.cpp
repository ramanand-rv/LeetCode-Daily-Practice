class Solution {
private:
    struct Node {
        char leftChar, rightChar;
        int length, prefix, suffix, best;
    };

    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right) {
        Node res;
        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;
        res.length = left.length + right.length;

        // Prefix
        res.prefix = left.prefix;
        if (left.rightChar == right.leftChar && left.prefix == left.length)
            res.prefix = left.length + right.prefix;

        // Suffix
        res.suffix = right.suffix;
        if (left.rightChar == right.leftChar && right.suffix == right.length)
            res.suffix = right.length + left.suffix;

        // Best
        res.best = max(left.best, right.best);
        if (left.rightChar == right.leftChar)
            res.best = max(res.best, left.suffix + right.prefix);

        return res;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {s[start], s[start], 1, 1, 1, 1};
            return;
        }
        int mid = (start + end) / 2;
        build(node * 2, start, mid, s);
        build(node * 2 + 1, mid + 1, end, s);
        tree[node] = mergeNodes(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {ch, ch, 1, 1, 1, 1};
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(node * 2, start, mid, idx, ch);
        else update(node * 2 + 1, mid + 1, end, idx, ch);
        tree[node] = mergeNodes(tree[node * 2], tree[node * 2 + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);

        vector<int> ans;
        for (int i = 0; i < queryIndices.size(); i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].best);
        }
        return ans;
    }
};