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
    vector<int> list;

    void f(TreeNode* root) {
        if(!root) {
            return;
        }

        f(root->left);
        list.push_back(root->val);
        f(root->right);
    }

    TreeNode* build(int l, int r) {
        if(l == r) {
            return new TreeNode(list[l]);
        }

        if(l > r) {
            return nullptr;
        }

        int m = (l + r) / 2;

        auto t = new TreeNode(list[m]);

        t->left = build(l, m-1);
        t->right = build(m+1, r);

        return t;
    }

    TreeNode* balanceBST(TreeNode* root) {
        f(root);

        return build(0, list.size()-1);
    }
};
