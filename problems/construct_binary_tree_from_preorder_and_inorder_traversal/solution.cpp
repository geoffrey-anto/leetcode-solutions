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
    TreeNode* f(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &m) {
        if(preStart > preEnd or inStart > inEnd) {
            return nullptr;
        }

        auto node = new TreeNode(preorder[preStart]);

        int val = m[preorder[preStart]];
        int rightNums = val - inStart;

        node->left = f(preorder, preStart+1, preStart+rightNums, inorder, inStart, val-1, m);
        node->right = f(preorder, preStart+rightNums+1, preEnd, inorder, val+1, inEnd, m);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> m;
        int x = 0;
        for(auto i: inorder) {
            m[i] = x;
            x++;
        }

        return f(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, m);
    }
};