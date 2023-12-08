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
    void preorderTraversal(TreeNode* node, string& ans) {
        if (node == nullptr) {
            return;
        }
        ans += to_string(node->val);
        if (node->left != nullptr || node->right != nullptr) {
            ans += "(";
            preorderTraversal(node->left, ans);
            ans += ")";
        }
        if (node->right != nullptr) {
            ans += "(";
            preorderTraversal(node->right, ans);
            ans += ")";
        }

    }
    string tree2str(TreeNode* root) {
        string ans = "";
        preorderTraversal(root, ans);
        return ans;
    }
    
};

