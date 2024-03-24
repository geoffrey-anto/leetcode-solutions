/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return nullptr;
        }

        auto r = root->val;
        auto pv = p->val;
        auto qv =  q->val;

        if(pv == r) {
            return root;
        }

        if(r == qv) {
            return root;
        }

        if((pv < r && qv > r) or (pv > r && qv < r)) {
            return root;
        }

        if(pv < r && qv < r) {
            return lowestCommonAncestor(root->left, p, q);
        }  else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};
