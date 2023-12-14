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
    TreeNode* f(vector<int>& preorder, int &i, int n, int limit) {
        if(i == n or preorder[i] > limit) {
            return nullptr;
        }

        auto node = new TreeNode();
        node->val = preorder[i];
        i++;
        node->left = f(preorder, i, n, node->val);
        node->right = f(preorder, i, n, limit);

        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        int i = 0;
        return f(preorder, i, n, 1001);   
    }
};