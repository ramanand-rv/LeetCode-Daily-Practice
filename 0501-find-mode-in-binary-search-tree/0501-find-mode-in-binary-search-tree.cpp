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
    vector<int>modes;
    vector<int> findMode(TreeNode* root) {
        in_order(root);
        return modes;
    }
    
    TreeNode* prev;
    int maxx = 0;
    int count = 1;
    void in_order(TreeNode* node){
        if(!node) return;
        
        in_order(node->left);
        
        if(prev && prev->val == node->val) count++;
        else count = 1;
        
        if(count > maxx){
            modes = {node->val};
            maxx = count;
        }
        else if(count == maxx)
            modes.push_back(node->val);
        
        prev = node;

        in_order(node->right);        
    }
};