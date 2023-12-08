/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    string _encode(TreeNode* root, string& encoded) {
        if(root == nullptr) {
            return "NULL,";
        }
        return to_string(root->val) + ',' + _encode(root->left, encoded) + _encode(root->right, encoded);
    }

    TreeNode* _decode(vector<string> &data, int &idx) {
        if(data[idx] == "NULL") {
            idx+=1;
            return NULL;
        }

        int d = stoi(data[idx]);
        auto node = new TreeNode(d);
        idx++;
        node->left = _decode(data, idx);
        node->right = _decode(data, idx);

        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encoded = "";
        encoded = _encode(root, encoded);
        encoded = encoded.substr(0,encoded.size()-1);
        cout << encoded <<endl;
        return encoded;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string s;
 
        vector<string> v;
    
        while (getline(ss, s, ',')) {
            v.push_back(s);
        }

        int x = 0;

        return _decode(v, x);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
