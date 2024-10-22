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
    int height(TreeNode* root) {
        if(!root) {
            return 0;
        }

        return max(1 + height(root->left), 1 + height(root->right));
    }

    void f(TreeNode* root, int i, vector<long long> &sums) {
        if(!root) {
            return;
        }

        sums[i] += root->val;
        f(root->left, i+1, sums);
        f(root->right, i+1, sums);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        int h = height(root);

        if(k > h) {
            return -1;
        }

        vector<long long> sums(h, 0);

        f(root, 0, sums);

        sort(rbegin(sums), rend(sums));

        return sums[k - 1];
    }
};
