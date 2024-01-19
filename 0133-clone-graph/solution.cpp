/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> mem;
public:
    Node* dfs(Node* node) {
        if(!node) {
            return nullptr;
        }
        if(mem.find(node) != mem.end()) {
            return mem[node];
        }

        mem[node] = new Node(node->val);

        for(auto &i: node->neighbors) {
            mem[node]->neighbors.push_back(dfs(i));
        }

        return mem[node];

    }
    Node* cloneGraph(Node* node) {
        if(!node) {
            return nullptr;
        }
        return dfs(node);
    }
};
