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
    pair<int, int> f(TreeNode* root) {
        if(!root) {
            return {0, 0};
        }

        if(!root->left && !root->right) {
            return {root->val, 1};
        }

        auto l = f(root->left);
        auto r = f(root->right);

        if(l.second == r.second) {
            return {l.first + r.first, l.second+1};
        } else if(l.second > r.second) {
            return {l.first, l.second + 1};
        } else {
            return {r.first, r.second + 1};
        }
    }

    int deepestLeavesSum(TreeNode* root) {
        return f(root).first;
    }
};
