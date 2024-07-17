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
    vector<TreeNode*> forest;

    void f(TreeNode* prev, bool lft, TreeNode* root, unordered_set<int> &s) {
        if(!root) {
            return;
        }

        if(s.count(root->val) > 0) {
            if(root->left) {
                f(root, true, root->left, s);
                f(root, false, root->right, s);
                forest.push_back(root->left);
            }

            if(root->right) {
                f(root, true, root->left, s);
                f(root, false, root->right, s);
                forest.push_back(root->right);
            }

            if(prev) {
                if(lft) {
                    prev->left = nullptr;
                } else {
                    prev->right = nullptr;
                }
            }

            delete root;
        } else {
            f(root, true, root->left, s);
            f(root, false, root->right, s);
        }

        

        return;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s(begin(to_delete), end(to_delete));
        if(!s.count(root->val) > 0)
            forest.push_back(root);

        f(nullptr, false, root, s);
        vector<TreeNode*> ans;

        for(auto &i: forest) {
            if(i) {
                ans.push_back(i);
            }
        } 

        return ans;
    }
};
