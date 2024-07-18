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
    int distance = 0;
    void getParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parents) {
        if(!root) {
            return;
        }

        if(root->left) {
            parents[root->left] = root;
            getParents(root->left, parents);
        }

        if(root->right) {
            parents[root->right] = root;
            getParents(root->right, parents);
        }
    }

    int dfs(int dist, TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parents, unordered_set<TreeNode*> &vis) {
        if(!root) {
            return 0;
        }

        // prune
        if(distance < dist) {
            return 0;
        }

        if(!root->left and !root->right) {
            // cout << dist << endl;
            if(distance >= dist) {
                return 1;
            }
        }

        vis.insert(root);

        int ans = 0;

        if(root->left && vis.count(root->left) == 0) {
            ans += dfs(dist+1, root->left, parents, vis);
        }

        if(root->right && vis.count(root->right) == 0) {
            ans += dfs(dist+1, root->right, parents, vis);
        }

        auto& parent = parents[root];

        if(parent && vis.count(parent) == 0) {
            ans += dfs(dist+1, parent, parents, vis);
        }

        return ans;
    }

    int f(TreeNode* root, int distance, unordered_map<TreeNode*, TreeNode*> &parents) {
        if(!root) {
            return 0;
        }

        if(!root->left and !root->right) {
            unordered_set<TreeNode*> vis;
            vis.insert(root);
            return dfs(1, parents[root], parents, vis);
        }

        int ans = 0;

        if(root->left) {
            ans += f(root->left, distance, parents);
        }
        if(root->right) {
            ans += f(root->right, distance, parents);
        }

        return ans;
    }

    int countPairs(TreeNode* root, int distance) {
        this->distance = distance;
        unordered_map<TreeNode*, TreeNode*> parents;
        getParents(root, parents);
        return f(root, distance, parents) / 2;
    }
};
