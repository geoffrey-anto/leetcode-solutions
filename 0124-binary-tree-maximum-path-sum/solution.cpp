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
    int f(TreeNode* root, int& cnt){
        if(root==nullptr){
            return 0;
        }

        int l = max(0, f(root->left, cnt));
        int r = max(0, f(root->right, cnt));

        cnt = max(cnt, l+r+root->val);

        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        int cnt=INT_MIN;

        f(root, cnt);

        return cnt;
    }
};
