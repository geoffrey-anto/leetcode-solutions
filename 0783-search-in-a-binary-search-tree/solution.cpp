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
    TreeNode* f(TreeNode* root, int val) {
        if(root->val == val) {
            return root;
        }

        if(root->val > val && root->left) {
            return f(root->left, val);
        } else if(root->val < val && root->right){
            return f(root->right, val);
        } else {
            return nullptr;
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return f(root, val);
    }
};
