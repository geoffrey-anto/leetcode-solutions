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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;

        int h = 0;

        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            vector<int> v;

            while(sz--) {
                v.push_back(q.front()->val);
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }

            if(h % 2 == 0) {
                if(v.size() == 1) {
                    if(v[0]%2 == 0) {
                        return false;
                    }
                }
                for(int i=0; i<v.size()-1; i++) {
                    if(v[i]%2 == 0 || v[i+1]%2 == 0) {
                        return false;
                    }
                    if(v[i] >= v[i+1]) {
                        return false;
                    }
                }
            } else {
                if(v.size() == 1) {
                    if(v[0]%2 != 0) {
                        return false;
                    }
                }
                for(int i=0; i<v.size()-1; i++) {
                    if(v[i]%2 != 0 || v[i+1]%2 != 0) {
                        return false;
                    }
                    if(v[i] <= v[i+1]) {
                        return false;
                    }
                }
            }

            h++;
        }

        return true;
    }
};
