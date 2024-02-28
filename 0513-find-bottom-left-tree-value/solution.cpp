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
    pair<int, int> ans;
    void f(TreeNode *root, int h) {
        if(!root) return;

        if(ans.first < h) {
            ans.first = h;
            ans.second = root->val;
        }

        f(root->left, h+1);
        f(root->right, h+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        ans.first = -1;
        ans.second = -1;

        f(root, 0);

        return ans.second;
    }
};
