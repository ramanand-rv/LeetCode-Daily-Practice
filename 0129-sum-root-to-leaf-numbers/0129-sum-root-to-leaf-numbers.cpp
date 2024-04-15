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
    long long res = 0;
    
    void inorder(TreeNode* node, long long n){
        if(!node) return;
        n+=node->val;
        n*=10;
        
        if(!node->left && !node->right){
            n /= 10;
            res += n;
        }
        
        inorder(node->left, n);
        inorder(node->right, n);
    }
    
    int sumNumbers(TreeNode* root) {
        long long n = 0;
        inorder(root, n);
        return res;
    }
};