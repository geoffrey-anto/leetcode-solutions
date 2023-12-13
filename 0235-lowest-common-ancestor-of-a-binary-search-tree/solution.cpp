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
        if(root == nullptr) {
            return nullptr;
        }

        int rVal = root->val;
        int pVal = p->val;
        int qVal = q->val;

        if(rVal == pVal) {
            return root;
        } else if(rVal == qVal) {
            return root;
        } else {
            if((rVal < qVal && pVal < rVal) or (rVal > qVal && pVal > rVal)) {
                return root;
            }
        }

        if(rVal > pVal && rVal > qVal) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};
