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

#define ll long long

class Solution {

bool isPossible(TreeNode* root, ll left, ll right){
    if(root == nullptr)  {
        return true;
    }
    if(root->val < right and root->val > left){
        if(isPossible(root->left, left, root->val) and isPossible(root->right, root->val, right)){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

public:
    bool isValidBST(TreeNode* root) {
        return isPossible(root, LLONG_MIN, LLONG_MAX);
    }
};
