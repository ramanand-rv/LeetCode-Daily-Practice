# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        count = 0

        def dfs(node):
            nonlocal count
            if not node:
                return 0, 0
            ls, lc = dfs(node.left)
            rs, rc = dfs(node.right)
            s = ls + rs + node.val
            c = lc + rc + 1
            if s // c == node.val:  # integer division
                count += 1
            return s, c

        dfs(root)
        return count
