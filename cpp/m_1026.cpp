/**
// Solved while drunk in 5 mins
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
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0, minAncestor = 1000001;
        int maxAncestor = 0;

        dfs(root, maxDiff, maxAncestor, minAncestor);

        return maxDiff;
    }

    void dfs(TreeNode* node, int& maxDiff, int maxAncestor, int minAncestor) {
        if (!node) {
            return;
        }

        maxAncestor = max(maxAncestor, node->val);
        minAncestor = min(minAncestor, node->val);

        maxDiff = max(maxDiff, max(abs(maxAncestor - node->val), abs(minAncestor - node->val)));

        dfs(node->left, maxDiff, maxAncestor, minAncestor);
        dfs(node->right, maxDiff, maxAncestor, minAncestor);
    }
};
