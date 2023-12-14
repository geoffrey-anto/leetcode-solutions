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
    TreeNode* p, *fp, *lp;
    void f(TreeNode* root) {
        if(root == nullptr) {
            return;
        }

        f(root->left);

        if(fp == nullptr && root->val < p->val) {
            fp = p;
        }

        if(fp != nullptr && root->val < p->val) {
            lp = root;
        }

        p = root;

        f(root->right);
    }
    void recoverTree(TreeNode* root) {
        p = new TreeNode(INT_MIN);
        fp = nullptr;
        lp = nullptr;

        f(root);

        swap(fp->val, lp->val);
    }
};