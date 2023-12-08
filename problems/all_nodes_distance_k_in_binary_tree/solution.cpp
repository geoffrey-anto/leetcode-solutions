/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void f(TreeNode* target, int k, unordered_map<TreeNode*, TreeNode*> &parent, unordered_map<TreeNode*, bool> &vis, vector<int> &ans, int i) {
        if(target == nullptr) {
            return;
        }

        if(vis.find(target) != vis.end() and vis[target]) {
            return;
        }

        if(i==k) {
            ans.push_back(target->val);
            return;
        }

        auto parentNode = parent.find(target);

        auto leftChild = target->left;
        auto rightChild = target->right;

        vis[target] = true;

        if(parentNode != parent.end()) {
            f(parent[target], k, parent, vis, ans, i+1);
        } 

        if(leftChild) {
            f(leftChild, k, parent, vis, ans, i+1);
        }

        if(rightChild) {
            f(rightChild, k, parent, vis, ans, i+1);
        }   
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int s = q.size();

            for(int i=0; i<s; i++) {
                auto front = q.front();
                q.pop();

                if(front->left != nullptr) {
                    mp[front->left] = front;
                    q.push(front->left);
                }

                if(front->right != nullptr) {
                    mp[front->right] = front;
                    q.push(front->right);
                }
            }
        }

        vector<int> ans;
        unordered_map<TreeNode*, bool> vis;
        
        f(target, k, mp, vis, ans, 0);

        return ans;
    }
};