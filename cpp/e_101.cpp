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
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || dfs(root->left, root->right);
    }

    bool dfs(TreeNode* l, TreeNode* r) {
        if (l == nullptr || r == nullptr) {
            return l == r;
        } else if (l->val != r->val) {
            return false;
        }
        return dfs(l->left, r->right) && dfs(l->right, r->left); 
    }
};
