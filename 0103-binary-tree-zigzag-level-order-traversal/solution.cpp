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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        queue<TreeNode*> q;

        if(root == nullptr) {
            return ans;
        }

        q.push(root);

        bool rev = false;

        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;

            for(int i=0; i<n; i++) {
                auto top = q.front();
                q.pop();
                if(top -> left != nullptr) q.push(top->left);
                if(top -> right != nullptr) q.push(top->right);
                temp.push_back(top->val);
            }
            
            if(rev) {
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
            rev = !rev;
        }

        return ans;
    }
};
