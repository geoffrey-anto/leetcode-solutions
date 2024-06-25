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
    int ans = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) {
            return nullptr;
        }

        if(root->right) {
            auto r = bstToGst(root->right);
        }

        ans += root->val;
        root->val = ans;

        if(root->left) {
            auto l = bstToGst(root->left);
        }

        return root;
    }
};
