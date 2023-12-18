# Symmetric Tree

## Leetcode Link: [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)
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
    bool f(TreeNode* NL, TreeNode* NR) {
        if(NL == nullptr and NR == nullptr){
            return true;
        }

        if(NL == nullptr or NR == nullptr){
            return false;
        }

        if(NL->val != NR->val) {
            return false;
        }

        return f(NL->left, NR->right) and f(NL->right, NR->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        return f(root->left, root->right);
    }
};```



