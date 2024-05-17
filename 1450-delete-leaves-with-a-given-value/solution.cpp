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
    TreeNode* f(TreeNode* root, int target) {
        if(!root) {
            return nullptr;
        }

        if(root->left) {
            root->left = f(root->left, target);
        }

        if(root->right) {
            root->right = f(root->right, target);
        }

        if(!root->left and !root->right and root->val == target) {
            return nullptr;
        }

        return root;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return f(root, target);
        // return root;
    }
};
