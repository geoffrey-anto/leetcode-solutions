// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     bool canFormPalindrome(string str){
//         int count[9] = { 0 };

//         for (int i = 0; str[i]; i++)
//             count[str[i] - '1']++;

//         int odd = 0;
//         for (int i = 0; i < 9; i++) {
//             if (count[i] & 1)
//                 odd++;

//             if (odd > 1)
//                 return false;
//         }
//         return true;
//     }

//     int res = 0;

//     void f(TreeNode* root, string x) {
//         if(root == nullptr) {
//             return;
//         }

//         if(root->left == nullptr && root->right == nullptr && canFormPalindrome(x+to_string(root->val))) {
//             res++;
//         }

//         f(root->left, x+to_string(root->val));
//         f(root->right, x+to_string(root->val));
//     }
//     int pseudoPalindromicPaths (TreeNode* root) {
//         f(root, "");
//         return res;
//     }
// };


class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        return countPseudoPalindromicPaths(root, 0);
    }

private:
    int countPseudoPalindromicPaths(TreeNode* node, int path) {
        if (!node) {
            return 0;
        }

        path ^= (1 << node->val);

        if (!node->left && !node->right) {
            return (path & (path - 1)) == 0 ? 1 : 0;
        }

        return countPseudoPalindromicPaths(node->left, path) + countPseudoPalindromicPaths(node->right, path);
    }
};



