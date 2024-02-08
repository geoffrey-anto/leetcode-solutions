# Leaf Similar Trees

## Leetcode Link: [Leaf Similar Trees](https://leetcode.com/problems/leaf-similar-trees/)
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
    void f(TreeNode* node, vector<int>& v) {
        if (node == NULL) return;

        if (node->left == NULL && node->right == NULL) {
            v.push_back(node->val);
        }

        f(node->left, v);
        f(node->right, v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;

        f(root1, v1);
        f(root2, v2);

        return v1 == v2;
    }

};```



