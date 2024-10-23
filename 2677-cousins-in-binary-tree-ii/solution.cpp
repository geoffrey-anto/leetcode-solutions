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
    void f(TreeNode* root, int h, vector<int> &mp) {
        if(!root) {
            return;
        }

        mp[h] += root->val;
        f(root->left, h+1, mp);
        f(root->right, h+1, mp);
    }

    void getCousinSum(TreeNode* root, int h, vector<int> &mp) {
        if(!root) {
            return;
        }

        int childSum = 0;
        int totalSumAtLevel = mp[h+1];

        if(root->left) {
            childSum += root->left->val;
        }

        if(root->right) {
            childSum += root->right->val;
        }

        if(root->left) {
            root->left->val = totalSumAtLevel - childSum;
        }

        if(root->right) {
            root->right->val = totalSumAtLevel - childSum;
        }

        getCousinSum(root->left, h+1, mp);
        getCousinSum(root->right, h+1, mp);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> mp(100001, 0);

        f(root, 0, mp);

        getCousinSum(root, 0, mp);

        // Since no cousins for root node
        root->val = 0;

        return root;
    }
};
