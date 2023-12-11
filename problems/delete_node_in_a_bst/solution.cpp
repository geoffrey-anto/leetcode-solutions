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
    TreeNode* getNode(TreeNode* root, int val) {
        if(root == nullptr) {
            return nullptr;
        }

        if(root->val == val) {
            return root;
        }

        if(root->val > val) {
            return getNode(root->left, val);
        } else {
            return getNode(root->right, val);
        }
    }

    TreeNode* getRightMost(TreeNode* node) {
        if(node->right == nullptr) return node;

        return getRightMost(node->right);
    }

    TreeNode* deleteNode(TreeNode* node) {
        if(node->left == nullptr) {
            return node->right;
        }

        if(node->right == nullptr) {
            return node->left;
        }
        auto r = node->right;

        auto rightMost = getRightMost(node->left);


        rightMost->right = r;
        
        return node->left;

    }

    TreeNode* f(TreeNode* root, int key) {
        TreeNode* temp = root;

        while(root != nullptr) {
            if(root->val < key) {
                if(root->right != nullptr and root->right->val == key) {
                    root->right = deleteNode(root->right);
                    break;
                } else {
                    root = root->right;
                }
            } else {
                if(root->left != nullptr and root->left->val == key) {
                    root->left = deleteNode(root->left);
                    break;
                } else {
                    root = root->left;
                }
            }
        }

        return temp;
    }


    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        
        if(root->val == key) return deleteNode(root);

        return f(root, key);
    }
};