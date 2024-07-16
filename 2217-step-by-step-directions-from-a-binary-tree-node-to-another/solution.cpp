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
    TreeNode* getNode(TreeNode* root, int n) {
        if(!root) {
            return nullptr;
        }

        if(root->val == n) {
            return root;
        }

        auto l = getNode(root->left, n);

        if(l) {
            return l;
        }

        auto r = getNode(root->right, n);

        if(r) {
            return r;
        }

        return nullptr;
    }

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

    

    TreeNode* LCA(TreeNode* root, TreeNode* start, TreeNode* dest) {
        if(!root) {
            return nullptr;
        }

        if(root == start or root == dest) {
            return root;
        }

        auto l = LCA(root->left, start, dest);
        auto r = LCA(root->right, start, dest);

        if(l && r) {
            return root;
        }

        return (l) ? l : r;
    }

    string getPath(TreeNode* root, TreeNode* child) {
        if(!root) {
            return "";
        }

        if(root == child) {
            return "X";
        }

        auto l = "L" + getPath(root->left, child);
        auto r = "R" + getPath(root->right, child);

        if(l[l.size() - 1] == 'X') {
            return l;
        } 

        if(r[r.size() - 1] == 'X') {
            return r;
        } 

        return "";
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* start = getNode(root, startValue);
        TreeNode* dest = getNode(root, destValue);
        
        // unordered_map<TreeNode*, TreeNode*> parents;

        // getParents(root, parents);

        // parents[root] = nullptr;

        TreeNode* lca = LCA(root, start, dest);

        string startPath = getPath(lca, start);
        string destPath = getPath(lca, dest);

        string res = "";

        for(auto i: startPath) {
            if(i != 'X')
                res += "U";
        }

        for(auto i: destPath) {
            if(i != 'X')
                res += i;
        }

        return res;
    }
};
