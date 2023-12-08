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
    TreeNode* f(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &m) {
        if(postStart > postEnd or inStart > inEnd) {
            return nullptr;
        }

        auto node = new TreeNode(postorder[postEnd]);

        int val = m[postorder[postEnd]];
        int rightNums = val - inStart;

        node->left = f(postorder, postStart, postStart+rightNums-1, inorder, inStart, val-1, m);
        node->right = f(postorder, postStart+rightNums, postEnd-1, inorder, val+1, inEnd, m);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> m;
        int x = 0;
        for(auto i: inorder) {
            m[i] = x;
            x++;
        }

        return f(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, m);
    }
};