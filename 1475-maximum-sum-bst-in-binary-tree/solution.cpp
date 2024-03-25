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

 #define np {INT_MAX, INT_MIN, 0}

class Solution {
public:
int ans = 0;
    tuple<int, int, int> f(TreeNode* root){
        if(root == nullptr)  {
            return np;
        }
           // l , r , mx  - left subtree
        auto [la, ra, va] = f(root->left);
           // l , r , mx  - right subtree
        auto [lb, rb, vb] = f(root->right);

        int c = root->val;


        if(!(c > ra && c < lb)) {
            return {INT_MIN, INT_MAX, 0};
        }

        ans = max(ans, va + vb + c);

        return {min(c, la), max(c, rb), va + vb + c};
    }
    int maxSumBST(TreeNode* root) {
        f(root);
        return ans;
    }
};
