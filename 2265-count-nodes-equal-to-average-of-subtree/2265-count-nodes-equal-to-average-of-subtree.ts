/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function averageOfSubtree(root: TreeNode | null): number {
    let count = 0;
    function dfs(node: TreeNode | null): [number, number] {
        if (!node) return [0, 0];
        const [ls, lc] = dfs(node.left);
        const [rs, rc] = dfs(node.right);
        const sum = ls + rs + node.val;
        const cnt = lc + rc + 1;
        if (Math.floor(sum / cnt) === node.val) count++;
        return [sum, cnt];
    }
    dfs(root);
    return count;
};