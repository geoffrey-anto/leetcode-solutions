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
    bool f(TreeNode* root) {
        if(!root) {
            return false;
        }

        if(root->val == 0 or root->val == 1) {
            return root->val;
        }

        bool l = f(root->left);
        bool r = f(root->right);

        if(root->val == 2) {
            return l or r;
        } else {
            return l and r;
        }
    }
    
    bool evaluateTree(TreeNode* root) {
        return f(root);
    }
};
