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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;

        if(root == nullptr) {
            return nullptr;
        }

        if(depth == 1) {
            TreeNode* temp = new TreeNode(val);

            temp->left = root;

            return temp;
        }

        int d = 1;

        q.push(root);

        while(!q.empty()) {
            int sz = q.size();

            for(int i=0; i<sz; i++) {
                TreeNode* top = q.front();
                q.pop();

                if(d+1 == depth) {
                    TreeNode* copy = top->left;
                    top->left = new TreeNode(val);
                    top->left->left = copy;

                    copy = top->right;
                    top->right = new TreeNode(val);
                    top->right->right = copy;
                } else {
                    if(top->left) q.push(top->left);
                    if(top->right) q.push(top->right);
                }
            }

            d++;
        }

        return root;
    }
};
