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
    void f(int h, TreeNode* root, vector<int>& ans) {
        if(!root) {
            return;
        }

        ans[h] = max(ans[h], root->val);

        f(h+1, root->left, ans);
        f(h+1, root->right, ans);
    }

    int depth(TreeNode* root) {
        if(!root) {
            return 0;
        }

        return 1 + max(depth(root->left), depth(root->right));
    }

    vector<int> largestValues(TreeNode* root) {
        int h = depth(root);

        vector<int> ans(h, INT_MIN);

        f(0, root, ans);

        return ans;
    }
};
