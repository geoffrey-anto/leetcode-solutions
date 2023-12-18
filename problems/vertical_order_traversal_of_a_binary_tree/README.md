# Vertical Order Traversal Of A Binary Tree

## Leetcode Link: [Vertical Order Traversal Of A Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)
### Language: C++

```cpp
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
    void f(TreeNode* root,int x,int y, map<int,vector<pair<int,int>>>&mp){
        if(root == nullptr) return;

        mp[x].push_back({y,root->val});

        // Left Down
        f(root->left,x-1,y+1,mp);

        // Right Down
        f(root->right,x+1,y+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>mp;

        f(root,0,0,mp);

        vector<vector<int>>ans;

        for(auto &n:mp){
          ans.push_back(vector<int>());

          sort(n.second.begin(), n.second.end());

          for(auto& m: n.second) {
            ans.back().push_back(m.second);
          }
        }

        return ans;
    }
    
};```



