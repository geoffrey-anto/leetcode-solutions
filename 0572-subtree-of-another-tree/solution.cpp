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
    bool check(TreeNode* root, TreeNode* subRoot) {
        if(!root and !subRoot) {
            return true;
        }

        if(!root) {
            return false;
        }

        if(!subRoot) {
            return false;
        }

        if(root->val != subRoot->val) {
            return false;
        }

        return check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }

    bool f(TreeNode* root, TreeNode* subRoot) {
        if(!root) {
            return false;
        }

        if(root->val == subRoot->val) {
            auto a = check(root, subRoot);
            if(a) {
                return true;
            }
        }
        
        auto b = f(root->left, subRoot);
        auto c = f(root->right, subRoot);


        return b or c;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return f(root, subRoot);
    }
};
