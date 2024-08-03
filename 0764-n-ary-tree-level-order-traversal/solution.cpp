/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
     `   val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;

        vector<vector<int>> ans;

        q.push(root);

        if(!root) {
            return ans;
        }


        while(!q.empty()) {
            int sz = q.size();

            vector<int> temp;

            for(int i=0; i<sz; i++) {
                auto top = q.front();
                q.pop();
                temp.push_back(top->val);
                for(auto i:top->children) {
                    if(i) {
                        q.push(i);
                    }
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
