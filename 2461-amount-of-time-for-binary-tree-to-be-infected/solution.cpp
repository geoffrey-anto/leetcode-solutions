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
    TreeNode* getNode(TreeNode* root, int start) {
        if(root == nullptr) {
            return nullptr;
        }

        if(root->val == start) {
            return root;
        }

        auto x = getNode(root->left, start);
        auto y = getNode(root->right, start);

        if(!x && !y) {
            return nullptr;
        }

        return x == nullptr ? y : x;
    }

    unordered_map<TreeNode*, TreeNode*> getParents(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> mp;

        mp[root] = nullptr;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            auto top = q.front();
            q.pop();

            if(top->left) {
                mp[top->left] = top;
                q.push(top->left);
            }

            if(top->right) {
                mp[top->right] = top;
                q.push(top->right);
            }
        }

        return mp;
    }

    unordered_map<TreeNode*, bool> vis;

    int dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parents) {
        if(root == nullptr) {
            return 0;
        }

        if(vis[root]) {
            return 0;
        }

        vis[root] = true;

        return max(
            1 + dfs(parents[root], parents),
            max(
                1 + dfs(root->left, parents),
                1 + dfs(root->right, parents)
            )
        );
    }

    int amountOfTime(TreeNode* root, int start) {
        auto node = getNode(root, start);

        auto parents = getParents(root);

        return dfs(node, parents) - 1;
    }
};
