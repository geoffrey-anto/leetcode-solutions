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
struct Node {
    int left = -1;
    int right = -1;
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_set<int> st, st1;

        for(auto &i: d) {
            st.insert(i[0]);
            st1.insert(i[1]);
        }

        TreeNode* root = nullptr;

        for(auto &i: st) {
            if(st1.find(i) == st1.end()) {
                root = new TreeNode(i);
            }
        }

        unordered_map<int, Node> mp;

        for(auto &i: d) {
            int par = i[0];
            int chld = i[1];
            int dir = i[2];

            if(dir == 1) {
                mp[par].left = chld;
            } else {
                mp[par].right = chld;
            }
        }

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            auto t = q.front();
            q.pop();

            int l = mp[t->val].left;
            int r = mp[t->val].right;

            if(l != -1) {
                t->left = new TreeNode(l);
                q.push(t->left);
            }
            
            if(r != -1) {
                t->right = new TreeNode(r);
                q.push(t->right);
            }
        }

        return root;
    }
};
