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
    int f(TreeNode* root, int mx, int mn) {
        if(!root) return (mx - mn);

        cout << mx << " " << mn << endl;

        mx = max(mx, root->val);
        mn = min(mn, root->val);

        return max(f(root->left, mx, mn), f(root->right, mx, mn));
    }
    int maxAncestorDiff(TreeNode* root) {
        return f(root, 0, INT_MAX);
    }
};
