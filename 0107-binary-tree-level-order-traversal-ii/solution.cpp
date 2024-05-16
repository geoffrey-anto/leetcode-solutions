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
    int mxD = 0;
    void f(TreeNode* root, int d, unordered_map<int, vector<int>> &mp) {
        if(root == nullptr) {
            return;
        }
        mxD = max(mxD, d);
        mp[d].push_back(root->val);
        f(root->left, d+1, mp);
        f(root->right, d+1, mp);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};

        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ans;

        f(root, 0, mp);

        for(int i=0; i<=mxD; i++) {
            ans.push_back(mp[i]);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
