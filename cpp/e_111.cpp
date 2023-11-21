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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int ret = INT_MAX;
        dfs(root, 1, ret);
        return ret == INT_MAX ? 0 : ret;
    }   

    void dfs(TreeNode* root, int localDepth, int& ret) {
        if (!root || localDepth > ret) return;
        dfs(root->left, localDepth + 1, ret);
        dfs(root->right, localDepth + 1, ret);
        if (!root->left && !root->right) ret = min(ret, localDepth);
    }
};
