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

        bool resl = f(root->left);
        bool resr = f(root->right);

        if(!resl) {
            root->left = nullptr;
        }

        if(!resr) {
            root->right = nullptr;
        }

        if(root->val == 1) {
            return true;
        } else {
            return (resl or resr);
        }
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool r = f(root);
        if(!r) {
            return nullptr;
        } 
        return root;
    }
};
