/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void inorder(TreeNode* node, int &sum, bool flg){
        if(node == NULL) return;
        if(!node->right && !node->left && flg){
            sum+= node->val;
        }
        
        inorder(node->left, sum, true);
        inorder(node->right, sum, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        inorder(root, sum, false);
        return sum;
    }
};