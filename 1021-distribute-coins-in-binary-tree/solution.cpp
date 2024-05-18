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
    vector<int> f(TreeNode* root) {
        if(!root) {
            return {0, 0};
        }

        auto l = f(root->left);
        auto r = f(root->right);

        int currSize = 1 + l[0] + r[0];

        int currVal = root->val;

        int currCost = l[1] + r[1] + currVal;

        ans += abs(currSize - currCost);

        return {currSize, currCost};
    }

    int distributeCoins(TreeNode* root) {
        f(root); return ans;
    }
};
