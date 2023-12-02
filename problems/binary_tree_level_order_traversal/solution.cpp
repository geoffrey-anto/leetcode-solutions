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

#define null nullptr
#define at ->

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;

        vector<vector<int>> ans;


        if(root == null) return ans;

        q.push(root);

        while(!q.empty()) {
            int s = q.size();
            vector<int> temp;
            for(int i=0; i<s; i++) {
                auto node = q.front();
                q.pop();
                temp.push_back(node at val);
                if(node at left != null) q.push(node at left);
                if(node at right != null) q.push(node at right);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};