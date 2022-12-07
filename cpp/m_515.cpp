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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;

        dfs(root, ret, 0);

        return ret;
    }

    void dfs(TreeNode* node, vector<int>& ret, int depth) {
        if (!node) {
            return;
        }

        if (ret.size() == depth) {
            ret.push_back(node->val);
        } else {
            ret[depth] = max(ret[depth], node->val);
        }

        dfs(node->left, ret, depth + 1);
        dfs(node->right, ret, depth + 1);
    }
};
