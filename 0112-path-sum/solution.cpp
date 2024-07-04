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
    int f(TreeNode* root, int sum, int targetSum) {
        if(!root) {
            return false;
        }
        
        if(!root->left and !root->right and sum + root->val == targetSum) {
            return true;
        }

        if(!root->left and !root->right and sum + root->val != targetSum) {
            return false;
        }

        return f(root->left, sum + root->val, targetSum) or f(root->right, sum + root->val, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root and targetSum == 0) {
            return false;
        }

        return f(root, 0, targetSum);
    }
};
