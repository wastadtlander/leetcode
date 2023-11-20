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
    bool isCousins(TreeNode* root, int x, int y) {
        vector<pair<TreeNode*, int>> p;
        if (root->val == x || root->val == y) return false;
        dfs(root, x, y, 0, p);
        return p[0].first != p[1].first && p[0].second == p[1].second;
    }

    void dfs(TreeNode* root, int x, int y, int depth, vector<pair<TreeNode*, int>>& p) {
        if (!root) return;
        if (root->left && (root->left->val == x || root->left->val == y)) p.push_back({root, depth});
        if (root->right && (root->right->val == x || root->right->val == y)) p.push_back({root, depth});
        dfs(root->left, x, y, depth + 1, p);
        dfs(root->right, x, y, depth + 1, p);
    }
};
