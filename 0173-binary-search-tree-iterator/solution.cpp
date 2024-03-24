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
class BSTIterator {
private:
    void inorder(TreeNode* root, vector<int> &ans) {
        if(root->left) {
            inorder(root->left, ans);
        }

        ans.push_back(root->val);

        if(root->right) {
            inorder(root->right, ans);
        }
    }
public:
    vector<int> ans;
    int currPtr = 0;
    int lim = 0;
    BSTIterator(TreeNode* root) {
        inorder(root, ans);
        lim = ans.size();
    }
    
    int next() {
        return ans[currPtr++];
    }
    
    bool hasNext() {
        return currPtr < lim;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
