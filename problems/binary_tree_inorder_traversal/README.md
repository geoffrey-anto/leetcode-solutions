# Binary Tree Inorder Traversal

## Leetcode Link: [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
### Language: C++

```cpp
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
    vector<int> mem;
    
    void inorder(TreeNode* root){
        if(root==nullptr){
            return;
        }
        inorder(root->left);
        mem.push_back(root->val);
        inorder(root->right);
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return mem;
    }
};```



