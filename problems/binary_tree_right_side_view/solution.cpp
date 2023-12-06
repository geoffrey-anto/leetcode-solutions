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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        map<int, int> mp;
        int level = 0;
        // mp[level] = root->val;
        // level++;

        while(!q.empty()) {
            int s = q.size();

            for(int i=0; i<s; i++) {
                auto front = q.front();
                q.pop();

                mp[level]=front->val;

                if(front->left) {
                    q.push(front->left);
                }
                if(front->right) {
                    q.push(front->right);
                }
            }
            level++;
        }

        for(auto it=mp.begin(); it!=mp.end(); it++) {
            ans.push_back((*it).second);
        }

        return ans;
    }
};