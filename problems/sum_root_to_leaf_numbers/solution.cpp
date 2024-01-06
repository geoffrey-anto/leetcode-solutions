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
    int f(TreeNode* root, int val) {
        if(root == nullptr) {
            return 0;
        }

        if(!root->left and !root->right) return val*10 + root->val;
        
        return f(root->left, val*10 + root->val) + f(root->right, val*10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
       return f(root, 0);
    }
};